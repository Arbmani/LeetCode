#include "string"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/**

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.


*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& str : strs){
            int zeros = count(str.begin(), str.end(), '0');
            int ones  = count(str.begin(), str.end(), '1');
            for (int i = m; i >= zeros; i--){
                for (int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;

    vector<string> strs1 = {"10","0001","111001","1","0"};
    vector<string> strs2 = {"10","0","1"};

    cout << "\nWant : 4\nWas  : " << s.findMaxForm(strs1, 5, 3) << endl;
    cout << "\nWant : 2\nWas  : " << s.findMaxForm(strs2, 1, 1) << endl;

    return 0;
}