#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/**

[Hard Problem]


Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and
if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.


*/
#include "unordered_map"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        vector<unordered_map<long long, int>> dp(nums.size());
        
        for(int index = 0; index < nums.size(); index++){
            for(int jhindex = 0; jhindex < index; jhindex++){
                long long diff   = (long long)nums[index] - nums[jhindex];
                int      count   = dp[jhindex][diff];
                dp[index][diff] += count;
                ans             += count;
                dp[index][diff] += 1;   
            }
        }

        return ans;
    }
};



int main(){
    Solution s;

    vector<int> nums1 = {2,4,6,8,10};
    vector<int> nums2 = {7,7,7,7,7};

    cout << "Want :  7, Was : " << s.numberOfArithmeticSlices(nums1) << endl;
    cout << "Want : 16, Was : " << s.numberOfArithmeticSlices(nums2) << endl;

    return -1;
}