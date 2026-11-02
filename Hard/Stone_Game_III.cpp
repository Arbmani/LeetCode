#include "string"
#include "vector"
#include "iostream"
#include <climits>

using namespace std;

/**

Alice and Bob continue their games with piles of stones. 
There are several stones arranged in a row, 
and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. 
On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. 
The score of each player is 0 initially.

The objective of the game is to end with the highest score, 
and the winner is the player with the highest score and there could be a tie. 
The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.


*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int sum = 0;
            dp[i] = INT_MIN;
            for(int k = 1; k<= 3 && i + k <= n; k++){
                sum += stoneValue[i + k - 1];
                dp[i] = max(dp[i], sum - dp[i + k]);
            }
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};


int main(){
    Solution s;

    vector<int> stoneValues1 = {1,2,3,7};
    vector<int> stoneValues2 = {1,2,3,-9};
    vector<int> stoneValues3 = {1,2,3,6};

    cout << "Want :   Bob, Was : " << s.stoneGameIII(stoneValues1) << endl;
    cout << "Want : Alice, Was : " << s.stoneGameIII(stoneValues2) << endl;
    cout << "Want :   Tie, Was : " << s.stoneGameIII(stoneValues3) << endl;

    return 0;
}