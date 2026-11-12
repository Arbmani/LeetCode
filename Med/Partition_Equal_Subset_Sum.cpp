#include "vector"
#include "iostream"
#include <numeric>

using namespace std;

/**

Given an integer array nums, return true if you can partition the array into 
two subsets such that the sum of the elements in both subsets is equal or false otherwise.

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums){
            for (int j = target; j >= num; j--) dp[j] = dp[j] || dp[j - num];
        }
        return dp[target];      
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};
 
    cout << "\nWant : true\nWas  : " << boolalpha << s.canPartition(nums1) << endl;
    cout << "\nWant : false\nWas  : " <<boolalpha <<  s.canPartition(nums2) << endl;


    return 0;
}