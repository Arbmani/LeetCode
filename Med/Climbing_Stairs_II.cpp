#include "vector"
#include "iostream"
#include <climits>
#include "algorithm"

using namespace std;

/**

You are climbing a staircase with n + 1 steps, numbered from 0 to n.

You are also given a 1-indexed integer array costs of length n, 
where costs[i] is the cost of step i.

From step i, you can jump only to step i + 1, i + 2, or i + 3. 
The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2

You start from step 0 with cost = 0.

Return the minimum total cost to reach step n.


*/

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";

    }
    os << "]";

    return os;
}


class Solution {
public:
    int climbStairs(int n, vector<int>& costs){
        int prev = 0, prev1 = 0, prev2 = 0;
        for (int i = 1; i <= n; i++){
            int curr = prev + costs[i - 1] + 1;
            if (i >= 2) curr = min(curr, prev1 + costs[i - 1] + 4);
            if (i >= 3) curr = min(curr, prev2 + costs[i - 1] + 9);
            prev2 = prev1;
            prev1 = prev;
            prev  = curr;
        }
        return prev;
    }


    int climbStairs_badmem(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j <= i + 3 && j <= n; j++){
                dp[j] = min(dp[j], dp[i] + (costs[j - 1] + (j - i)*(j - i))); 
            } 
        }
        return dp[n];
    }
};

int main(){
    Solution s;

    vector<int> costs1 = {1, 2, 3, 4};
    vector<int> costs2 = {5, 1, 6, 2};
    vector<int> costs3 = {9, 8 , 3};

    cout << "\nWant : 13\nWas  : " << s.climbStairs(4, costs1) << endl;
    cout << "\nWant : 11\nWas  : " << s.climbStairs(4, costs2) << endl;
    cout << "\nWant : 12\nWas  : " << s.climbStairs(3, costs3) << endl;


    return 0;
}