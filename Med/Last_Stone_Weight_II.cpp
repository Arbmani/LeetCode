#include "vector"
#include "iostream"
#include "numeric"

using namespace std;

/**

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, 
we choose any two stones and smash them together. 
Suppose the stones have weights x and y with x <= y. The result of this smash is:

-   If x == y, both stones are destroyed, and

-   If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.


*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total   = accumulate(stones.begin(), stones.end(), 0);
        int target  = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones){
            for (int j = target; j >= stone; j--){
                dp[j] = dp[j] || dp[j - stone];
            }
        }
        for (int j = target; j >= 0; j--){
            if (dp[j]) return total - 2*j;
        }

        return 0;
    }
};


int main(){
    Solution s;

    vector<int> stones1 = {2,7,4,1,8,1};
    vector<int> stones2 = {31,26,33,21,40};

    cout << "\nWant : 1\nWas  : " << s.lastStoneWeightII(stones1) << endl;
    cout << "\nWant : 5\nWas  : " << s.lastStoneWeightII(stones2) << endl;

    return 0;
}