#include "vector"
#include "iostream"
#include <algorithm>

using namespace std;

/**

You are given an integer array nums.

In one move, you may increase the value of any single element nums[i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxelem = *max_element(nums.begin(), nums.end());
        int ans     = 0;
        for (int num : nums) ans += maxelem - num;
        return ans;
        
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {4, 4, 5};


    cout << "Want : 3, Was : " << s.minMoves(nums1) << endl;
    cout << "Want : 2, Was : " << s.minMoves(nums2) << endl;


    return 0;
}