#include "vector" 
#include "iostream" 

using namespace std;

/**

You are given an m x n matrix grid and a positive integer k. 
An island is a group of positive integers (representing land) 
that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by k.
*/

class Solution {
public:
    long long dfs(vector<vector<int>>& grid, const int& rows, const int& cols, int row, int col){
        if (row < 0 || col < 0 || rows <= row || cols <= col || grid[row][col] == 0) return 0;
        long long ans       = grid[row][col];
        grid[row][col]      = 0;
        
        long long down      = dfs(grid, rows, cols, row + 1, col);
        long long up        = dfs(grid, rows, cols, row - 1, col);
        long long left      = dfs(grid, rows, cols, row, col - 1);
        long long right     = dfs(grid, rows, cols, row, col + 1);
        return ans + down + up + left + right;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<long long> ans;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] != 0){
                    ans.push_back(dfs(grid, rows, cols, row, col));
                }
            }
        }
        int res = 0;
        for(const long long val : ans){
            if (val % k == 0) res++;
        }
        return res;
    }
};


int main(){
    Solution s;

    vector<vector<int>> grid1 = {{0,2,1,0,0}, {0,5,0,0,5}, {0,0,1,0,0}, {0,1,4,7,0}, {0,2,0,0,8}};
    vector<vector<int>> grid2 = {{3,0,3,0}, {0,3,0,3}, {3,0,3,0}};

    cout << "Want : 2, Was : " << s.countIslands(grid1, 5) << endl;
    cout << "Want : 6, Was : " << s.countIslands(grid2, 3) << endl;


    return 0;
}