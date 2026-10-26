#include "vector" 
#include "iostream"
#include <ios>

using namespace std;
/**

Given an array nums with n integers, 
your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] 
holds for every i (0-based) such that (0 <= i <= n - 2).

*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for (int index = 0; index < nums.size() - 1; index++){
            if (nums[index] <= nums[index + 1])                     continue;
            if (changed)                                            return false;
            if (index == 0 || nums[index + 1] >= nums[index - 1])   nums[index] = nums[index + 1]; 
            else                                                    nums[index + 1] = nums[index];
            changed = true;
        }
        return true;
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {4,2,3};
    vector<int> nums2 = {4,2,1};
    cout << "Want :  true, Was : " << boolalpha << s.checkPossibility(nums1) << endl;
    cout << "Want : false, Was : " << boolalpha << s.checkPossibility(nums2) << endl;

    return 0;
}