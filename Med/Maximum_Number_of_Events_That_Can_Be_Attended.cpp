#include "vector"
#include "iostream"
#include "algorithm"
#include "queue"
#include <queue>



using namespace std;

/**

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.

Return the maximum number of events you can attend.



*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = events.size(), i = 0, days = 0, ans = 0;
        
        
        while (i < n || !minHeap.empty()){
            if (minHeap.empty()) days = events[i][0];

            while (i < n && events[i][0] <= days) {
                minHeap.push(events[i][1]);
                i++;
            }

            while (!minHeap.empty() && minHeap.top() < days) minHeap.pop();
            if (!minHeap.empty()) {
                minHeap.pop();
                days++;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    
    vector<vector<int>> events1 = {{1,2}, {2,3}, {3,4}};
    vector<vector<int>> events2 = {{1,2}, {2,3}, {3,4}, {1,2}};

    vector<vector<int>> events3 = {{1,4}, {4,4}, {2,2}, {3,4}, {1,1}};

    cout << "\nWant : 3\nWas  : " << s.maxEvents(events1) << endl;
    cout << "\nWant : 4\nWas  : " << s.maxEvents(events2) << endl;

    cout << "\nWant : 4\nWas  : " << s.maxEvents(events3) << endl;

    return 0;
}