#include "vector"
#include "iostream"
#include <climits>

using namespace  std;

/**

You are given an integer array nums of length n, 
where nums is a permutation of the numbers in the range [0..n - 1].

You may swap elements at indices i and j only if nums[i] AND nums[j] == k, 
where AND denotes the bitwise AND operation and k is a non-negative integer.

Return the maximum value of k such that the array can be sorted in non-decreasing order 
using any number of such swaps. If nums is already sorted, return 0.

*/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        for(int index = 0; index < nums.size(); index++){
            if (nums[index] != index) ans &= index;
        }
        return  ans == -1 ? 0 : ans;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {0, 3, 2, 1};
    vector<int> nums2 = {0, 1, 3, 2};
    vector<int> nums3 = {3, 2, 1, 0};
    
    vector<int> nums4 = {0,1};
    vector<int> nums5 = {0,2, 1};

    cout << "Want : 1, Was : " << s.sortPermutation(nums1) << endl;
    cout << "Want : 2, Was : " << s.sortPermutation(nums2) << endl;
    cout << "Want : 0, Was : " << s.sortPermutation(nums3) << endl;

    cout << "Want : 0, Was : " << s.sortPermutation(nums4) << endl;
    cout << "Want : 0, Was : " << s.sortPermutation(nums5) << endl;


    return 0;
}