#include "vector" 
#include "algorithm"
#include "numeric"

#include "iostream"
#include <algorithm>
#include <numeric>

using namespace std;

/**

Given an integer array nums and an integer k, 
split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



*/

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxAllowedSum){
        int numberOfSubarrays   = 1;
        int currentSubarraySum  = 0;

        for (int num : nums){
            if (currentSubarraySum + num > maxAllowedSum){
                numberOfSubarrays++;
                currentSubarraySum = num;
            }
            else{
                currentSubarraySum += num;
            }
        }
        return numberOfSubarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int smallestPossibleMaxSum = *max_element(nums.begin(), nums.end());
        int largestPossibleMaxSum  = accumulate(nums.begin(), nums.end(), 0);

        int minimumLargestSum = largestPossibleMaxSum;
        
        while (smallestPossibleMaxSum <= largestPossibleMaxSum) {
            int allowedMaxSum = smallestPossibleMaxSum + (largestPossibleMaxSum - smallestPossibleMaxSum) / 2;
            if (canSplit(nums, k, allowedMaxSum)){
                minimumLargestSum = allowedMaxSum;
                largestPossibleMaxSum = allowedMaxSum - 1;
            }
            else{
                smallestPossibleMaxSum = allowedMaxSum + 1;
            }
        }
        
        return minimumLargestSum;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {7,2,5,10,8};
    vector<int> nums2 = {1,2,3,4,5};

    cout << "Want : 18, Was : " << s.splitArray(nums1, 2) << endl;
    cout << "Want : 9, Was : " << s.splitArray(nums2, 2) << endl;

    return 0;
}