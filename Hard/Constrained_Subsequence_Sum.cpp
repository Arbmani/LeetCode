#include "vector" 
#include "iostream"
#include <climits>
#include <deque>
#include <algorithm>

using namespace std;

/**

Given an integer array nums and an integer k, 
return the maximum sum of a non-empty subsequence of 
that array such that for every two consecutive integers 
in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of 
elements (can be zero) from the array, leaving the remaining elements in their original order.


*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int maxSubsequence = nums[0];
        deque<int> bestPreviousSum;
        
        for(int i = 0; i < nums.size(); i++){
            if(!bestPreviousSum.empty()) nums[i] += bestPreviousSum.front();
            maxSubsequence = max(maxSubsequence, nums[i]);
            while(!bestPreviousSum.empty() && bestPreviousSum.back() < nums[i]) bestPreviousSum.pop_back();
            if (nums[i] > 0) bestPreviousSum.push_back(nums[i]);
            if (i >= k                      &&
                !bestPreviousSum.empty()    &&
                bestPreviousSum.front() == nums[i - k]) bestPreviousSum.pop_front();
        }
        return maxSubsequence;
    }

    int Giga_Slow_constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n);
        for (int index = 0; index < n; index++){
            dp[index] = nums[index];
            for(int j = max(0, index - k); j < index; j++){
                dp[index] = max(dp[index], nums[index] + dp[j]);
            }
            ans = max(ans, dp[index]);
        }
        return ans;      
    }
};


int main(){
    Solution s;


    vector<int> nums1 = {10,2,-10,5,20};
    vector<int> nums2 = {-1,-2,-3};
    vector<int> nums3 = {10,-2,-10,-5,20};


    cout << "Want : 37, Was : " << s.constrainedSubsetSum(nums1, 2) << endl;
    cout << "Want : -1, Was : " << s.constrainedSubsetSum(nums2, 1) << endl;
    cout << "Want : 23, Was : " << s.constrainedSubsetSum(nums3, 2) << endl;

    return 0;
}