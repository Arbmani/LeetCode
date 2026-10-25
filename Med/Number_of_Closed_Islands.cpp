#include "iostream"
#include <vector>

using namespace  std;

/**

Given a 2D grid consists of 0s (land) and 1s (water).  
An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally 
(all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

*/

class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int rows, int cols, int row, int col){
        if (row < 0 || col < 0 || rows <= row || cols <= col) return false;
        if (grid[row][col]) return true;
        grid[row][col] = 1;
        bool down  = dfs(grid, rows, cols, row + 1, col);
        bool right = dfs(grid, rows, cols, row, col + 1);
        bool left  = dfs(grid, rows, cols, row - 1, col);
        bool up    = dfs(grid, rows, cols, row, col - 1);

        return down && right && left && up;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 0 && dfs(grid, rows, cols, row, col)) ans++;
            }
        }
        return ans;
    }
};


int main(){
    Solution s;

    vector<vector<int>> grid1 = {{1,1,1,1,1,1,1,0}, {1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},
                                 {1,0,0,0,0,1,0,1}, {1,1,1,1,1,1,1,0}};
    vector<vector<int>> grid2 = {{0,0,1,0,0}, {0,1,0,1,0}, {0,1,1,1,0}};
    vector<vector<int>> grid3 = {{1,1,1,1,1,1,1}, {1,0,0,0,0,0,1}, {1,0,1,1,1,0,1}, {1,0,1,0,1,0,1},
                                 {1,0,1,1,1,0,1}, {1,0,0,0,0,0,1}, {1,1,1,1,1,1,1}};

    cout << "Want : 2, Was : " << s.closedIsland(grid1) << endl;
    cout << "Want : 1, Was : " << s.closedIsland(grid2) << endl;
    cout << "Want : 2, Was : " << s.closedIsland(grid3) << endl;

    return 0;
}