#include "iostream"
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> rank;
    vector<int> parent;   
    int components;

    UnionFind(int nodes){
        rank.resize(nodes, 1);
        parent.resize(nodes);
        components = nodes;

        for(int index = 0; index < nodes; index++){
            parent[index] = index;
        }
    }
    int find(int node){
        while(parent[node] != node){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    void unite(int first, int second){
        int root1 = find(first);
        int root2 = find(second);

        if (root1 == root2) return;
        if (rank[root1] < rank[root2]){
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
        else{
            parent[root2] = root1;
            rank[root1] += rank[root2];
        }
        components--;
    }
    int getComponents(){return components;}
    void decrementComponents(){components--;}
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        UnionFind uf(rows*cols);

        for (int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '0'){
                    uf.decrementComponents();
                    continue;
                }
                int a = col + row * cols;
                if(row + 1 < rows && grid[row + 1][col] == '1'){
                    int b = col + (row + 1) * cols;
                    uf.unite(a, b);
                }
                if(col + 1 < cols && grid[row][col + 1] == '1'){
                    int b = (col + 1) + row * cols;
                    uf.unite(a, b);
                }
            }
        }
        return uf.components;    
    }
};

class Solution2 {
public:
    void consume_island(vector<vector<char>>&grid, int row, int col, int rows, int cols){
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') return;
        grid[row][col] = '0';
        consume_island(grid, row - 1, col, rows, cols);
        consume_island(grid, row + 1, col, rows, cols);
        consume_island(grid, row, col - 1, rows, cols);
        consume_island(grid, row, col + 1, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid){
        int islands = 0, rows = grid.size(), cols = grid[0].size();
        for(int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    islands++;
                    consume_island(grid, row, col, rows, cols);
                }
            }
        }
        return islands;
    }
};


int main(){

    vector<vector<char>> grid1 = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    vector<vector<char>> grid2 = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution2 s;
    cout << "Want : 1, Was : " << s.numIslands(grid1) << endl;
    cout << "Want : 3, Was : " << s.numIslands(grid2) << endl;


    return -1;
}


