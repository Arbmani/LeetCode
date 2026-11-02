#include "iostream"
#include "vector"
#include "algorithm"
#include <climits>

using namespace std;

/**

We are playing the Guessing Game. The game will work as follows:

1.  I pick a number between 1 and n.

2.  You guess a number.

3.  If you guess the right number, you win the game.

4.  If you guess the wrong number, then I will tell you whether 
    the number I picked is higher or lower, and you will continue guessing.

5.  Every time you guess a wrong number x, you will pay x dollars. 
    If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.



*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; len++){
            for (int left = 1; left + len - 1 <= n; left++){
                int right = left + len - 1;
                dp[left][right] = INT_MAX;
                for (int k = left; k <= right; k++){
                    int cost        = k + max(dp[left][k - 1], dp[k + 1][right]);
                    dp[left][right] =     min(dp[left][right], cost);
                }
            }
        }
        return dp[1][n];    
    }
};


int main(){
    Solution s;

    cout << "Want : 16, Was : " << s.getMoneyAmount(10) << endl;
    cout << "Want :  0, Was : " << s.getMoneyAmount(1) << endl;
    cout << "Want :  1, Was : " << s.getMoneyAmount(2) << endl;

    return 0;
}