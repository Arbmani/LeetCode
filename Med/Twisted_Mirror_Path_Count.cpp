#include "vector"
#include "iostream"

using namespace std;

/**

Given an m x n binary grid grid where:

-   grid[i][j] == 0 represents an empty cell, and

-   grid[i][j] == 1 represents a mirror.

A robot starts at the top-left corner of the grid (0, 0) 
and wants to reach the bottom-right corner (m - 1, n - 1). 
It can move only right or down. 
If the robot attempts to move into a mirror cell, it is reflected before entering that cell:

-   If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.

-   If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the mirror.

If this reflection would cause the robot to move outside the grid boundaries, 
the path is considered invalid and should not be counted.

Return the number of unique valid paths from (0, 0) to (m - 1, n - 1).

Since the answer may be very large, return it modulo 10^9 + 7.

Note: If a reflection moves the robot into a mirror cell, 
the robot is immediately reflected again based on the direction 
it used to enter that mirror: if it entered while moving right, 
it will be turned down; if it entered while moving down, 
it will be turned right. This process will continue until either the last cell is reached, 
the robot moves out of bounds or the robot moves to a non-mirror cell.


*/

class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    int dfs(vector<vector<int>>& dp, const vector<vector<int>>& grid, const int& rows, const int& cols, int row, int col, int dir){
        if (row < 0 || col < 0 || row >= rows || col >= cols)   return 0;
        if (row == rows - 1 && col == cols - 1)                 return 1;
        if (grid[row][col] == 1){
            if (dir == 1)   return dfs(dp, grid, rows, cols, row, col + 1, -1);
            else            return dfs(dp, grid, rows, cols, row + 1, col, +1);
        }
        if (dp[row][col] != - 1) return dp[row][col];
        int right   = dfs(dp, grid, rows, cols, row, col + 1, -1);
        int down    = dfs(dp, grid, rows, cols, row + 1, col, +1);
        return dp[row][col] = (down + right) % mod;

    }

    int uniquePaths(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return dfs(dp, grid, rows, cols, 0, 0, 0);
    }
};


int main(){
    Solution s;

    vector<vector<int>> grid1 = {{0,1,0}, {0,0,1},{1,0,0}};
    vector<vector<int>> grid2 = {{0,0}, {0,0}};
    vector<vector<int>> grid3 = {{0,1,1}, {1,1,0}};

    cout << "Want : 5, Was : " << s.uniquePaths(grid1) << endl;
    cout << "Want : 2, Was : " << s.uniquePaths(grid2) << endl;
    cout << "Want : 1, Was : " << s.uniquePaths(grid3) << endl;

    return 0;
}