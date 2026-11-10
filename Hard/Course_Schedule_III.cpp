#include "iostream"
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

/**

There are n different online courses numbered from 1 to n. 
You are given an array courses where courses[i] = [durationi, lastDayi] 
indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.


*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> maxHeap;
        int totalTime = 0;

        for (auto& course : courses){
            int duration = course[0];
            int deadline = course[1];
            totalTime += duration;
            maxHeap.push(duration);
            if (totalTime > deadline){
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};

int main(){
    Solution s;

    vector<vector<int>> courses1 = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    vector<vector<int>> courses2 = {{1,2}};
    vector<vector<int>> courses3 = {{3,2}, {4, 3}};

    cout << "\nWant : 3\nWas  : " << s.scheduleCourse(courses1) << endl;
    cout << "\nWant : 1\nWas  : " << s.scheduleCourse(courses2) << endl;
    cout << "\nWant : 0\nWas  : " << s.scheduleCourse(courses3) << endl;

    return 0;
}