#include "functional"
#include "set"
#include "utility"

#include "vector"
#include "iostream"

using namespace std;

/**

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<pair<int,int>> visit;

        function<int(int, int)> dfs = [&](int row, int col) -> int {
            if (row < 0 || col < 0 || row >= rows || col >= cols || !grid[row][col] || visit.count({row, col})) return 0;
            visit.insert({row, col});
            int res = 1;
            int direct[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1,0}};
            for (auto& d: direct){
                res += dfs(row + d[0], col + d[1]);
            }
            return res;
        };
        int land = 0, borderLand = 0;
        for (int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                land += grid[row][col];
                if (grid[row][col] && !visit.count({row, col}) && (col == 0 || col == cols -1 || row == 0 ||row == rows -1)){
                    borderLand += dfs(row, col);
                }
            }
        }
        return land - borderLand;
    }
};

int main(){
    Solution s;

    vector<vector<int>> grid1 = {{0,0,0, 0}, {1,0,1,0}, {0,1,1,0}, {0,0,0,0}};
    vector<vector<int>> grid2 = {{0,1,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,0}};

    cout << "Want : 3, Was  : " << s.numEnclaves(grid1) << endl;
    cout << "Want : 0, Was  : " << s.numEnclaves(grid2) << endl;

    return 0;
}