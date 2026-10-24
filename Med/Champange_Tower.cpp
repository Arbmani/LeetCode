#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

/**
We stack glasses in a pyramid, where the first row has 1 glass, 
the second row has 2 glasses, and so on until the 100th row.  
Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  
When the topmost glass is full, any excess liquid poured will 
fall equally to the glass immediately to the left and right of it.  
When those glasses become full, any excess champagne will fall 
equally to the left and right of those glasses, and so on.  
(A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full. 
After two cups of champagne are poured, the two glasses on the second row are half full. 
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  
After four cups of champagne are poured, the third row has the middle 
glass half full, and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, 
return how full the jth glass in the ith row is (both i and j are 0-indexed.)
*/


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev_row = {(double)poured};

        for(int row = 1; row <= query_row; row++){
            vector<double> cur_row(row + 1, 0.0);
            for(int col = 0; col < row; col ++){
                double extra = prev_row[col] - 1;
                if(extra > 0){
                    cur_row[col]        += 0.5 * extra;
                    cur_row[col + 1]    += 0.5 * extra;
                }
            }
            prev_row = cur_row;
        }
        return min(1.0, prev_row[query_glass]);      
    }
};


int main(){
    Solution s;

    cout << " Want : 0.00000, Was : " << s.champagneTower(1, 1, 1) << endl;
    cout << " Want : 0.50000, Was : " << s.champagneTower(2, 1, 1) << endl;
    cout << " Want : 1.00000, Was : " << s.champagneTower(100000009, 33, 17) << endl;


    return 0;
}