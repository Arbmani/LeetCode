#include "vector"
#include "iostream"

using namespace std;

/**

A wiggle sequence is a sequence where the differences between successive numbers strictly 
alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

-   For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) 
    alternate between positive and negative.

-   In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
    The first is not because its first two differences are positive, and the second is not because its last difference is zero.

A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, 
leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.


*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1, prevDiff = 0;
        for (int index = 1; index < nums.size(); index++){
            int diff = nums[index] - nums[index - 1];
            if ((diff > 0 && prevDiff <= 0) || 
                (diff < 0 && prevDiff >= 0)){
                    count++;
                    prevDiff = diff;
                }
        }
        return count;        
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,7,4,9,2,5};
    vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums3 = {1,2,3,4,5,6,7,8,9};


    cout << "Want : 6, Was : " << s.wiggleMaxLength(nums1) << endl;
    cout << "Want : 7, Was : " << s.wiggleMaxLength(nums2) << endl;
    cout << "Want : 2, Was : " << s.wiggleMaxLength(nums3) << endl;

    return 0;
}