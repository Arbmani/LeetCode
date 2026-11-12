#include "vector"
#include "iostream"
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

/**

There are n piles of coins on a table. 
Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, 
remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting 
the composition of the ith pile from top to bottom, and a positive integer k,
return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

*/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, INT_MIN);
        dp[0] = 0;

        for (const auto& pile : piles){
            vector<int> prefix(pile.size() + 1, 0);
            for (int j = 0; j < pile.size(); j++) prefix[j + 1] = prefix[j] + pile[j];

            vector<int> nextDP(k + 1, INT_MIN);
            for (int i = 0; i <= k; i++){
                if (dp[i] == INT_MIN) continue;
                for (int j = 0; j <= min((int)pile.size(), k - i); j++){
                    nextDP[i + j] = max(nextDP[i + j], dp[i] + prefix[j]);
                }
            }
            dp = std::move(nextDP);
        }

        return dp[k];
    }
};

int main(){
    Solution s;

    vector<vector<int>> piles1 = {{1, 100, 3}, {7, 8, 9}};
    vector<vector<int>> piles2 = {{100}, {100}, {100}, {100}, {100}, {100}, {1,1,1,1,1,1,700}};
    cout << "\nWant : 101\nWas  : " << s.maxValueOfCoins(piles1, 2) << endl;
    cout << "\nWant : 706\nWas  : " << s.maxValueOfCoins(piles2, 7) << endl;


    return 0;
}