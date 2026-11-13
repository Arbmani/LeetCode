#include "vector"
#include "iostream"
#include "deque"
#include <climits>


using namespace std;

/**

You are given an array points containing the coordinates of points on a 2D plane, 
sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. 
You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.


*/

// 6 + 5 + | - 1 - 3| = 15
// 7 + 5 + | 0 - 3  | = 15 

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        deque<int> que;
        long long ans = LLONG_MIN;  

        for (int j = 0; j < n; j++){
            while(!que.empty() && points[j][0] - points[que.front()][0] > k) que.pop_front();
            if   (!que.empty()){
                int i           = que.front();
                long long value = (long long)points[i][1] - points[i][0] + points[j][1] + points[j][0]; 
                ans             = max(ans, value); 
            }
            while(!que.empty() && (long long)points[que.back()][1] - points[que.back()][0] <= (long long)points[j][1] - points[j][0]) que.pop_back();
            que.push_back(j);
        }
        return (int)ans;
    }
};

int main(){
    Solution s;

    vector<vector<int>> points1 = {{1, 3}, {2,0}, {5, 10}, {6, -10}};
    vector<vector<int>> points2 = {{0,0}, {3,0}, {9,2}};

    cout << "\nWant : 4\nWas  : " << s.findMaxValueOfEquation(points1, 1) << endl;
    cout << "\nWant : 3\nWas  : " << s.findMaxValueOfEquation(points2, 3) << endl;


    return 0;
}