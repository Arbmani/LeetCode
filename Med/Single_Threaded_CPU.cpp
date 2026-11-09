#include "vector"
#include "iostream"
#include <functional>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;

template<typename T> 
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for ( int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";


    return os;
}

/**

You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, 
where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available 
to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

-   If the CPU is idle and there are no available tasks to process, the CPU remains idle.

-   If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 
    If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.

-   Once a task is started, the CPU will process the entire task without stopping.

-   The CPU can finish a task then start a new one instantly.

Return the order in which the CPU will process the tasks.



*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks;
                                    // {[0] = Enqueue Time, [1] = Processing Time, [2] = Original Index}
        for (int i = 0; i < n; i++) sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        sort(sortedTasks.begin(), sortedTasks.end());
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !minHeap.empty()){
            if (minHeap.empty() && time < sortedTasks[i][0]) time = sortedTasks[i][0];
            while (i < n && sortedTasks[i][0] <= time){
                minHeap.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }
            auto [processingTime, index] = minHeap.top();
            minHeap.pop();
            ans.push_back(index);
            time += processingTime;
        }


        return ans;
    }
};

int main(){
    Solution s;

    vector<vector<int>> tasks1 = {{1,2}, {2,4}, {3, 2}, {4,1}};
    vector<vector<int>> tasks2 = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7,2}};

    vector<int> out1 = {0,2,3,1};
    vector<int> out2 = {4,3,2,0,1};

    cout << "\nWant : " << out1 << "\nWas  : " << s.getOrder(tasks1) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.getOrder(tasks2) << endl;

    return 0;
}