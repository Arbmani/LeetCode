#include "iostream"
#include "ostream"
#include <vector>


using namespace std;



class Solution {
public:
    int rows, cols;
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited, int prevheight){
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || heights[row][col] < prevheight) return;
        visited[row][col] = true;
        dfs(row + 1, col, heights, visited, heights[row][col]);
        dfs(row - 1, col, heights, visited, heights[row][col]);
        dfs(row, col + 1, heights, visited, heights[row][col]);
        dfs(row, col - 1, heights, visited, heights[row][col]);


    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for (int col = 0; col < cols; col++){
            dfs(0, col, heights, pac, heights[0][col]);
            dfs(rows - 1, col, heights, atl, heights[rows - 1][col]);
        }
        for (int row = 0; row < rows; row++){
            dfs(row, 0, heights, pac, heights[row][0]);
            dfs(row, cols - 1, heights, atl, heights[row][cols - 1]);
        }
        vector<vector<int>> ans;
        for (int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(pac[row][col] && atl[row][col]) ans.push_back({row, col});
            }
        }
        return ans;
    }
};



template <typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if (index + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

int main(){
    Solution s;

    vector<vector<int>> heights1 = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}};
    vector<vector<int>> heights2 = {{1}};
    
    vector<vector<int>> out1     = {{0,4},{1,3}, {1,4},{2,2},{3,0},{3,1},{4,0}};
    vector<vector<int>> out2     = {{0,0}};

    cout << "Want : " << out1 << ", Was : " << s.pacificAtlantic(heights1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.pacificAtlantic(heights2) << endl;


}