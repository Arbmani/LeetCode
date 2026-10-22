#include "iostream"
#include <unordered_map>
#include <vector>

using namespace std;

/**

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells 
matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
if they have some coordinate that is different: for example, if x1 != x1'.

*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        vector<vector<int>> sub_sum(ROWS, vector<int>(COLS, 0));
        for(int row = 0; row < ROWS; row++){
            for(int col = 0; col < COLS; col++){
                int top             = (row > 0) ? sub_sum[row - 1][col] : 0;
                int left            = (col > 0) ? sub_sum[row][col - 1] : 0;
                int top_left        = (row > 0 && col > 0) ? sub_sum[row - 1][col - 1] : 0;

                sub_sum[row][col]   = matrix[row][col] + top + left - top_left; 
            }
        }

        int res = 0;

        for(int row_1 = 0; row_1 < ROWS; row_1++){
            for(int row_2 = row_1; row_2 < ROWS; row_2++){
                unordered_map<int, int> count;
                count[0] = 1;

                for(int col = 0; col < COLS; col++){
                    int cur_sum = sub_sum[row_2][col] - (row_1 > 0 ? sub_sum[row_1 - 1][col] : 0);
                    int diff    = cur_sum - target;
                    res        += count[diff];
                    count[cur_sum]++;
                }
            }

        }



        return res;
    }
};


int main(){
    Solution s;

    vector<vector<int>> matrix1 = {{0,1,0},{1,1,1},{0,1,0}};
    vector<vector<int>> matrix2 = {{1,-1},{-1,1}};
    vector<vector<int>> matrix3 = {{904}};

    cout << "Want : 4, Was : " << s.numSubmatrixSumTarget(matrix1, 0) << endl;
    cout << "Want : 5, Was : " << s.numSubmatrixSumTarget(matrix2, 0) << endl;
    cout << "Want : 0, Was : " << s.numSubmatrixSumTarget(matrix3, 0) << endl;


    return -1;
}