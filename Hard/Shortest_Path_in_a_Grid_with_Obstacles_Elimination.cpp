#include "vector"
#include "iostream"
#include "queue"
#include "tuple"



using namespace std;

/**

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.


Return the minimum number of steps to walk from the upper left corner (0, 0) 
to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        if (k >= rows + cols - 2) return rows + cols - 2;
        queue<tuple<int, int, int, int>> que;
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        que.push({0, 0, 0, k});
        visited[0][0] = k;
        vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


        while (!que.empty()){
            auto [row, col, steps, remaining] = que.front();
            que.pop();
            if (row == rows - 1 && col == cols - 1) return steps;
            for (auto move : moves){
                int newRow = row + move[0];
                int newCol = col + move[1];
                if (newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
                int newRemaining = remaining - grid[newRow][newCol];
                if (newRemaining < 0) continue;
                if (visited[newRow][newCol] >= newRemaining) continue;
                visited[newRow][newCol] = newRemaining;
                que.push({newRow, newCol, steps + 1, newRemaining});
            }
        }

        return -1;
    }
};



class Solution_bad {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        queue<tuple<int, int, int>> que;
        vector<vector<vector<bool>>> visisted(rows, vector<vector<bool>>(cols, vector<bool>(k + 1, false)));
        que.push({0,0,0});
        visisted[0][0][0] = true;
        vector<vector<int>> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};        
        int steps = 0;

        while(!que.empty()){
            int size = que.size();
            while (size --){
                auto [row, col, used] = que.front();
                que.pop();

                if (row == rows - 1 && col == cols - 1) return steps;
                for (auto move : moves){
                    int dr = row + move[0];
                    int dc = col + move[1];
                    if (dr < 0 || dr >= rows || dc < 0 || dc >= cols) continue;
                    int newUsed = used + grid[dr][dc];
                    if (newUsed > k) continue;
                    if (visisted[dr][dc][newUsed]) continue;
                    visisted[dr][dc][newUsed] = true;
                    que.push({dr, dc, newUsed});
                }
            }
            steps++;
        }
        return -1;
    }
};

int main(){
    Solution s;

    vector<vector<int>> grid1 = {{0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0}};
    vector<vector<int>> grid2 = {{0,1,1}, {1,1,1}, {1,0,0}};

    cout << "\nWant : 6\nWas  : " << s.shortestPath(grid1, 1) << endl;
    cout << "\nWant : -1\nWas  : " << s.shortestPath(grid2, 1) << endl;


    return 0;
}