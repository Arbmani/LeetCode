#include "vector"
#include "iostream"
#include "queue"
#include "tuple"
#include "algorithm"
#include <queue>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}


/**

You are given two 0-indexed integer arrays servers and tasks 
of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, 
and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.

Tasks are assigned to the servers using a task queue. 
Initially, all servers are free, and the queue is empty.

At second j, the jth task is inserted into the queue 
(starting with the 0th task being inserted at second 0). 
As long as there are free servers and the queue is not empty, 
the task in the front of the queue will be assigned to a free server 
with the smallest weight, and in case of a tie, it is assigned to a free 
server with the smallest index.

If there are no free servers and the queue is not empty, 
we wait until a server becomes free and immediately assign the next task. 
If multiple servers become free at the same time, then multiple tasks from 
the queue will be assigned in order of insertion following the weight and index priorities above.

A server that is assigned task j at second t will be free again at second t + tasks[j].

Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

Return the array ans​​​​.



*/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue         <pair<int, int>,
                        vector <pair<int, int>>,
                        greater<pair<int, int>>> available;
        priority_queue         <tuple<long long, int, int>,
                        vector <tuple<long long, int, int>>,
                        greater<tuple<long long, int, int>>> busy;

        for (int i = 0; i < n; i++) available.push({servers[i], i});
        vector<int> ans(m);
        long long currentTime = 0;
        for (int i = 0; i < m; i++){
            currentTime = max(currentTime, (long long)i);
            while (!busy.empty() && get<0>(busy.top()) <= currentTime){
                auto [freetime, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }
            if (available.empty()){
                currentTime = get<0>(busy.top());
                while(!busy.empty() && get<0>(busy.top()) <= currentTime){
                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();
                    available.push({weight, index});
                }
            }
            auto [weight, index] = available.top();
            available.pop();
            ans[i] = index;
            busy.push({currentTime + tasks[i], weight, index});
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> servers1 = {3,3,2};
    vector<int> servers2 = {5,1,4,3,2};


    vector<int> tasks1 = {1,2,3,2,1,2};
    vector<int> tasks2 = {2,1,2,4,5,2,1};

    vector<int> outs1 = {2,2,0,2,1,2};
    vector<int> outs2 = {1,4,1,4,1,3,2};

    cout << "\nWant : " << outs1 << "\nWas  : " << s.assignTasks(servers1, tasks1) << endl;
    cout << "\nWant : " << outs2 << "\nWas  : " << s.assignTasks(servers2, tasks2) << endl;

    return 0;
}