#include "string"
#include "vector"
#include "iostream"

using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows <= 1 || numRows >= n) return s;

        vector<string> rows(numRows);
        int row         = 0;
        int direction   = 1;

        for (char cha : s){
            rows[row] += cha;
            if (row == 0){
                direction = 1;
            } else if (row == numRows - 1){
                direction = -1;
            }
            row += direction;
        }
        string result;
        result.reserve(n);
        for(const string& row: rows){
            result += row;
        }
        return result;      
    }
};


int main(){
    Solution s;

    cout << "Want : PAHNAPLSIIGYIR, Was : " << s.convert("PAYPALISHIRING", 3) << endl;
    cout << "Want : PINALSIGYAHRPI, Was : " << s.convert("PAYPALISHIRING", 4) << endl;
    cout << "Want : A, Was : " << s.convert("A", 1) << endl;


    return -1;
}