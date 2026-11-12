#include "vector"
#include "iostream"
#include "numeric"
#include <numeric>

using namespace std;

/**

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' 
before each integer in nums and then concatenate all the integers.

-   For example, if nums = [2, 1], you can add a '+' before 2 and a '-' 
    before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.


*/

class Solution {
public:
    // Positive + Negative = Total
    // Positive - Negative = Target
    // Target + Total = (Positive + Negative) + (Positive - Negative) = 2P
    // Positive Sum = Target + Total / 2 
    // Therefore we need to find all positive sums that are equal to: Target + Total / 2

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < abs(target))    return 0;
        if ((total + target) % 2 != 0) return 0;
        int subsetSum = (total + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums){
            for (int j = subsetSum; j >= num; j--) dp[j] += dp[j - num];
        }
        return dp[subsetSum];
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,1,1,1,1};
    vector<int> nums2 = {1};
    vector<int> nums3 = {7, 2};

    cout << "\nWant : 5\nWas  : " << s.findTargetSumWays(nums1, 3) << endl;
    cout << "\nWant : 1\nWas  : " << s.findTargetSumWays(nums2, 1) << endl;

    cout << "\nWant : 1\nWas  : " << s.findTargetSumWays(nums3, -5) << endl;


    return 0;
}