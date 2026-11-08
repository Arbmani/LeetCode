#include "vector"
#include "iostream"

using namespace std;


/**

You are given a map of a server center, 
represented as a m * n integer matrix grid, 
where 1 means that on that cell there is a server 
and 0 means that it is no server. Two servers are said to 
communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        int ans = 0;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1 && (rowCount[row] > 1 || colCount[col] > 1)){
                    ans ++;
                }
            }
        }
        return ans;
    }
};


class Solution_Works_ButSlow {
public:
    // first down stop
    int dfs(vector<vector<int>>& grid, const int& rows, const int& cols, int row, int col){
        grid[row][col] = 0;
        int ans = 1;
        for (int i = 0; i < rows; i++){
            if (grid[i][col] == 1){
                ans += dfs(grid, rows, cols, i, col);
                break;
            }
        }
        for (int i = 0; i < cols; i++){
            if (grid[row][i] == 1){
                ans += dfs(grid, rows, cols, row, i);
                break;
            }
        }
        return ans;
    }

    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans  = 0; 
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    int val = dfs(grid, rows, cols, row, col);
                    ans += val == 1 ? 0 : val;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<vector<int>> grid1 = {{1,0}, {0,1}};
    vector<vector<int>> grid2 = {{1,0}, {1, 1}};
    vector<vector<int>> grid3 = {{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};

    vector<vector<int>> grid4 = {{0,0,1,0,1}, {0,1,0,1,0}, {0,1,1,1,0}, {1,0,0,1,1}, {0,0,1,1,0}};

    cout <<"\nWant : 0\nWas  : " << s.countServers(grid1) << endl;
    cout <<"\nWant : 3\nWas  : " << s.countServers(grid2) << endl;
    cout <<"\nWant : 4\nWas  : " << s.countServers(grid3) << endl;

    cout <<"\nWant : 12\nWas  : " << s.countServers(grid4) << endl;


    return 0;
}


