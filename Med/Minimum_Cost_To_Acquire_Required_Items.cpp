#include "iostream"

using namespace std;

/**
You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

-   An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.

-   An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.

-   An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.

You must collect enough items so that the total contribution 
toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.



*/

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common    = min(need1, need2);
        long long ans       = common * min(1LL * costBoth, 1LL* (cost1 + cost2));
        need1   -= common;
        need2   -= common;
        ans     += 1LL * need1 * min(cost1, costBoth); 
        ans     += 1LL * need2 * min(cost2, costBoth); 
        return ans;
    }


    long long minimumCostUgly(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if (cost1 + cost2 >= costBoth){
            ans += 1LL * min(need1, need2) * costBoth;
            if (need1 > need2){
                need1 -= need2;
            } else {
                need1  = need2 - need1;
                cost1  = cost2;
            }
            if (cost1 >= costBoth){
                ans += 1LL* costBoth * need1;
            } else{
                ans += 1LL* cost1 * need1;
            }
            return ans;
        }
        return 1LL* cost1 * need1 + 1LL*cost2 * need2;
    }
};

int main(){
    Solution s;

    cout << "\nWant : 3\nWas  : " << s.minimumCost(3, 2, 1, 3, 2) << endl;
    cout << "\nWant : 22\nWas  : " << s.minimumCost(5, 4, 15, 2, 3) << endl;
    cout << "\nWant : 0\nWas  : " << s.minimumCost(5, 4, 15, 0, 0) << endl;


    return 0;
}