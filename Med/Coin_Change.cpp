#include "vector"
#include "iostream"
#include <climits>
#include <vector>
#include "climits"
using namespace std;

/**

[Medium Problem]

You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> map(amount + 1, INT_MAX);
        map[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins) {
                if (coin <= i && map[i - coin] != INT_MAX) {
                    map[i] = min(map[i], 1 + map[i - coin]);
                }
            }
        }
        return map[amount] == INT_MAX ? -1 : map[amount];
    }
};

int main(){
    Solution s;

    vector<int> coins1 = {1,2,5};
    vector<int> coins2 = {2};
    vector<int> coins3= {1};
    cout << "Want : 3, Was : " << s.coinChange(coins1, 11) << endl;
    cout << "Want : -1, Was : " << s.coinChange(coins2, 3) << endl;
    cout << "Want : 0, Was : " << s.coinChange(coins3, 0) << endl;
 

    return -1;
}
