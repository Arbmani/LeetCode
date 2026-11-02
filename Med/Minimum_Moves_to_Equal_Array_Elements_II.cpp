#include "vector"
#include "algorithm"
#include "cstdlib"
#include "iostream"

using namespace std;

/**

Given an integer array nums of size n, 
return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.



*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median  = nums[nums.size() / 2];
        int counter = 0;
        for (int num : nums) counter += abs(num - median);
        return counter;
    }
};


int main(){
    Solution s;
    
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,10,2, 9};


    cout << "Want :  2, Was : " << s.minMoves2(nums1) << endl;
    cout << "Want : 16, Was : " << s.minMoves2(nums2) << endl;


    return 0;
}