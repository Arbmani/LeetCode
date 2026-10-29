#include "vector"
#include "iostream"
#include <functional>

using namespace std;

/**

You are given two 0-indexed integer arrays, cost and time, 
of size n representing the costs and the time taken to paint n different 
walls respectively. There are two painters available:

-   A paid painter that paints the ith wall in time[i] 
    units of time and takes cost[i] units of money.

-   A free painter that paints any wall in 1 unit of time at a cost of 0. 
    But the free painter can only be used if the paid painter is already occupied.

Return the minimum amount of money required to paint the n walls.


*/



class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const long long INF = 1e15;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));

        function<long long(int, int)> dfs = [&](int index, int remain) -> long long {
            if (remain            <= 0)     return 0;
            if (index             == n)     return INF;
            if (dp[index][remain] != -1)    return dp[index][remain];
            long long paint = cost[index] + dfs(index + 1, remain - 1 - time[index]);
            long long skip  = dfs(index + 1, remain);
            return dp[index][remain] = min(paint, skip);
        };
        return (int)dfs(0, n);
    }
};


int main(){
    Solution s;

    vector<int> cost1 = {1,2,3,2};
    vector<int> cost2 = {2,3,4,2};
    vector<int> time1 = {1,2,3,2};
    vector<int> time2 = {1,1,1,1};

    cout << "Want : 3, Was : " << s.paintWalls(cost1, time1) << endl;
    cout << "Want : 4, Was : " << s.paintWalls(cost2, time2) << endl;

    return 0;
}