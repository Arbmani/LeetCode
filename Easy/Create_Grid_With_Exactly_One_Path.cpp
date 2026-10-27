#include "string"
#include "vector"
#include "iostream"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int index = 0; index < vec.size(); index++){
        os << "[";
        os << vec[index];
        os << "]";
        if(index + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

/**

You are given two integers m and n, representing the number of rows and columns of a grid.

Construct any m x n grid consisting only of the characters '.' and '#', where:

'.' represents a free cell.
'#' represents an obstacle cell.
A valid path is a sequence of free cells that:

Starts at the top-left cell (0, 0).
Ends at the bottom-right cell (m - 1, n - 1).
Moves only:
Right, from (i, j) to (i, j + 1), or
Down, from (i, j) to (i + 1, j).
Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.


*/

class Solution {
public:
    vector<string> createGrid(int rows, int cols) {
        vector<string> grid(rows, string(cols, '#'));
        for (int col = 0; col < cols; col++) grid[0][col]           = '.';
        for (int row = 0; row < rows; row++) grid[row][cols - 1]    = '.';

        return grid;
    }
};



int main(){
    Solution s;

    vector<string> out1 = {"..#","#.."};
    vector<string> out2 = {"..#","#..","##."};
    vector<string> out3 = {"...."};

    cout << "Want : " << out1 << ", Was : " << s.createGrid(2, 3) << endl;
    cout << "Want : " << out2 << ", Was : " << s.createGrid(3, 3) << endl;
    cout << "Want : " << out3 << ", Was : " << s.createGrid(1, 4) << endl;

    return 0;
}