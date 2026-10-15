#include "vector"
#include "iostream"
#include <vector>


using namespace std;
/**
[Medium Problem]


You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution{
public:
    int rob_1(vector<int>& nums, int left, int right){
        int prev1 = 0, prev2 = 0, curMax;
        for(int index = left; index <= right; index++){
            curMax = max(prev1, prev2 + nums[index]);
            prev2      = prev1;
            prev1      = curMax;
        }
        return  prev1;
    }
    int rob(vector<int>& nums){
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        return max(rob_1(nums, 0, size -2), rob_1(nums, 1, size - 1));
    }

};



int main() {
    Solution s;

    vector<int> nums1 = {2,3,2};
    vector<int> nums2 = {1,2,3,1};
    vector<int> nums3 = {1,2,3};

    cout << "Want : 3, Was : " << s.rob(nums1) << endl;
    cout << "Want : 4, Was : " << s.rob(nums2) << endl;
    cout << "Want : 3, Was : " << s.rob(nums3) << endl;


    return -1;
}








