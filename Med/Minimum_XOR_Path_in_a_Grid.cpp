#include "vector"
#include "iostream"
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_set>

using namespace std;

/**

You are given a 2D integer array grid of size m * n.

You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).

At each step, you may move either right or down.

The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.

Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).




*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int& rows, int& cols, int row, int col, int val) {
        if (row < 0 || col < 0 || rows <= row || cols <= col) return INT_MAX;
        val = val ^ grid[row][col];
        if (row == rows - 1 && col == cols - 1) return val;
        int down  = dfs(grid, rows, cols, row + 1, col, val);
        int right = dfs(grid, rows, cols, row, col + 1, val);
        return min(right, down);
    }

    int minCost_toslow(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        return dfs(grid, rows, cols, 0, 0, 0);        
    }

    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<unordered_set<int>>> dp(rows, vector<unordered_set<int>>(cols));
        dp[0][0].insert(grid[0][0]);

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if (row == 0 && col == 0) continue;
                if (row  > 0) for (int val : dp[row - 1][col]) dp[row][col].insert(val ^ grid[row][col]);
                if (col  > 0) for (int val : dp[row][col - 1]) dp[row][col].insert(val ^ grid[row][col]);
            }
        }
        return *min_element(dp[rows - 1][cols - 1].begin(), dp[rows - 1][cols - 1].end());      
    }

};

int main(){
    Solution s;
    vector<vector<int>> grid1 = {{1,2}, {3,4}};
    vector<vector<int>> grid2 = {{6,7}, {5, 8}};
    vector<vector<int>> grid3 = {{2,7,5}};

    cout << "Want : 6, Was : " << s.minCost(grid1) << endl;
    cout << "Want : 9, Was : " << s.minCost(grid2) << endl;
    cout << "Want : 0, Was : " << s.minCost(grid3) << endl;

    return 0;
}

