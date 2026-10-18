#include <ostream>
#include <vector>
#include "iostream"
#include "ostream"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

/**
[Medium Problem]

According to Wikipedia's article: 

    "The Game of Life, also known simply as Life, is a cellular automaton devised by 
    the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: 
live (represented by a 1) or dead (represented by a 0). 

Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
using the following four rules (taken from the above Wikipedia article):

    1.  Any live cell with fewer than two live neighbors dies as if caused by under-population.
    
    2.  Any live cell with two or three live neighbors lives on to the next generation.
    
    3.  Any live cell with more than three live neighbors dies, as if by over-population.
    
    4.  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.


*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows    = board.size(), cols = board[0].size();
        // int cells   = rows * cols;
        // index into cells -> col + row * cols
        vector<int> cells(rows*cols, 0);
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int live_neighbors = 0;
                if(row - 1 >= 0 && col - 1 >= 0)        live_neighbors += board[row - 1][col - 1];
                if(row - 1 >= 0)                        live_neighbors += board[row - 1][col];
                if(col - 1 >= 0)                        live_neighbors += board[row][col - 1];
                if(row + 1 < rows)                      live_neighbors += board[row + 1][col];
                if(col + 1 < cols)                      live_neighbors += board[row][col + 1];
                if(row - 1 >= 0 && col + 1 < cols)      live_neighbors += board[row - 1][col + 1];
                if(row + 1 < rows && col + 1 < cols)    live_neighbors += board[row + 1][col + 1];
                if(row + 1 < rows && col - 1 >= 0)      live_neighbors += board[row + 1][col - 1];
                cells[col + row * cols] = live_neighbors;
            }
        }
        for(int index = 0; index < cells.size(); index++){
            int col = index % cols;
            int row = index / cols; 
            int live_neighbors = cells[index];
            if ((board[row][col] == 1) && 
                (live_neighbors < 2 || live_neighbors > 3))         board[row][col] = 0;
            else if((board[row][col] == 0) && live_neighbors == 3)  board[row][col] = 1;
        }
    }
};


int main(){
    Solution s;
    vector<vector<int>> board1  = {{0,1,0},{0,0,1},{1,1, 1}, {0, 0, 0}};
    vector<vector<int>> out1    = {{0,0,0},{1,0,1},{0,1, 1}, {0, 1, 0}};

    vector<vector<int>> board2 = {{1,1},{1,0}};
    vector<vector<int>> out2    = {{1,1}, {1,1}};
    s.gameOfLife(board1);
    s.gameOfLife(board2);
    cout << "Want : " << out1 << ", Was : " << board1 << endl; 
    cout << "Want : " << out2 << ", Was : " << board2 << endl; 


    return -1;
}