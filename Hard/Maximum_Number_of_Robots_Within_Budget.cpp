#include "vector"
#include "iostream"
#include "algorithm"
#include "deque"

using namespace std;

/**

You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, 
both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] 
units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), 
where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is 
the sum of running costs among the k robots.


Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

*/


template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}


class Solution_fail {
private:
    struct Group{ 
        int cost;
        int wait;
    };

    friend ostream& operator<<(ostream& os, const Group& g){
    os << "{cost : " << g.cost << ", wait : " << g.wait << " }";
    return os;
    }


public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        vector<Group> groups(n, {0, 0});
        for (int i = 0; i < n; i++){
            groups[i].cost = runningCosts[i];
            groups[i].wait = chargeTimes[i];
        }
        sort(groups.begin(), groups.end(), [](const Group& a, const Group&b) {
            if (a.wait != b.wait) return a.wait < b.wait;
            return a.cost < b.cost;
        });
        cout << "\ngroups are : \n" << groups << endl;


        //  Find max "K" (NVM robots are supposed to be a subarray)
        //  -   Limited by : max(chargeTimes) + k * sum(runningCosts) <= budget

        return -1;
    }
};

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        deque<int> que;
        long long sum   = 0;
        int left        = 0;
        int ans         = 0;
        
        for (int right = 0; right < n; right++){
            while (!que.empty() && chargeTimes[que.back()] <= chargeTimes[right]) que.pop_back();
            que.push_back(right);
            sum += runningCosts[right];

            while(!que.empty() && chargeTimes[que.front()] + (long long)(right - left + 1) * sum > budget){
                if (que.front() == left) que.pop_front();
                sum -= runningCosts[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


int main(){
    Solution s;

    vector<int> chargeTimes1 = {3,6,1,3,4};
    vector<int> chargeTimes2 = {11,12,19};

    vector<int> runningCosts1 = {2,1,3,4,5};
    vector<int> runningCosts2 = {10,8,7};

    cout << "\nWant : 3\nWas  : " << s.maximumRobots(chargeTimes1, runningCosts1, 25) << endl; 
    cout << "\nWant : 0\nWas  : " << s.maximumRobots(chargeTimes2, runningCosts2, 19) << endl; 


    return 0;
}