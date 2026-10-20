#include <vector>
#include "iostream"
#include "climits"

using namespace std;

/**
[Medium Problem]

An integer array is called arithmetic if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.


*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int cur = 0;
        int ans = 0;
        for(int index = 2; index < nums.size(); index++){
            if(nums[index] - nums[index - 1] == nums[index - 1] - nums[index - 2]){
                cur ++;
                ans += cur;
            } else cur = 0;
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {1};

    cout << "Want : 3, Was : " << s.numberOfArithmeticSlices(nums1) << endl;
    cout << "Want : 0, Was : " << s.numberOfArithmeticSlices(nums2) << endl;

    return -1;
}