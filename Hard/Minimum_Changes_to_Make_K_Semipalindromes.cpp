#include "string"
#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

/**

Given a string s and an integer k, partition s into k substrings 
such that the letter changes needed to make each substring a 
semi-palindrome are minimized.

Return the minimum number of letter changes required.

A semi-palindrome is a special type of string that can 
be divided into palindromes based on a repeating pattern. 
To check if a string is a semi-palindrome:​

1.  Choose a positive divisor d of the string's length. 
    d can range from 1 up to, but not including, the string's length. 
    For a string of length 1, it does not have a valid divisor as per this definition, 
    since the only divisor is its length, which is not allowed.

2.  For a given divisor d, divide the string into groups where each 
    group contains characters from the string that follow a repeating pattern 
    of length d. Specifically, the first group consists of characters 
    at positions 1, 1 + d, 1 + 2d, and so on; the second group includes 
    characters at positions 2, 2 + d, 2 + 2d, etc.

3.  The string is considered a semi-palindrome if each of these groups 
    forms a palindrome.

Consider the string "abcabc":

-   The length of "abcabc" is 6. Valid divisors are 1, 2, and 3.

-   For d = 1: The entire string "abcabc" forms one group. Not a palindrome.

-   For d = 2:
    
    -   Group 1 (positions 1, 3, 5): "acb"
    
    -   Group 2 (positions 2, 4, 6): "bac"
    
    -   Neither group forms a palindrome.

-   For d = 3:
    
    -   Group 1 (positions 1, 4): "aa"
    
    -   Group 2 (positions 2, 5): "bb"
    
    -   Group 3 (positions 3, 6): "cc"
    
    -   All groups form palindromes. Therefore, "abcabc" is a semi-palindrome.


*/

class Solution {
private:
    static constexpr int INF = 1e9;
    vector<vector<int>> precomputeCost(const string& s){
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int len = j - i + 1;
                for (int d = 1; d < len; d++){
                    if (len % d != 0) continue;
                    int groupSize = len / d;
                    int changes   = 0;
                    for (int r = 0; r < d; r++){
                        for (int t = 0; t < groupSize / 2; t++){
                            int left = i + r + t * d;
                            int right = i + r + (groupSize - 1 - t) * d;
                            if (s[left] != s[right]) changes++;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        return cost;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        if (k * 2 > n) return -1;
        vector<vector<int>> cost = precomputeCost(s);
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++){
            for (int i = 2 * p; i <= n; i++){
                for (int j = 2 * (p - 1); j <= i - 2; j++){
                    if (dp[p - 1][j] == INF) continue;
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                }
            } 
        }
        return dp[k][n] == INF ? -1 : dp[k][n];
    }
};

int main(){
    Solution s;


    cout << "\nWant : 1\nWas  : " << s.minimumChanges("abcac", 2) << endl;
    cout << "\nWant : 2\nWas  : " << s.minimumChanges("abcdef", 2) << endl;
    cout << "\nWant : 0\nWas  : " << s.minimumChanges("aabbaa", 3) << endl;

    return 0;
}