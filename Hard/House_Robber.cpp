#include "vector"
#include "iostream"

using namespace std;

/**
[Medium Problem]

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses 
have security systems connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
public:
    int rob(vector<int>& nums){
        int prev1 = 0, prev2 = 0;
        for(int money: nums) {
            int currMax = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = currMax;
        }
        return prev1;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {1,2,3,1};
    vector<int> nums3 = {2,1,1,2};

    cout << "Want : 4, Was ; " << s.rob(nums1) << endl;
    cout << "Want : 4, Was ; " << s.rob(nums2) << endl;    
    cout << "Want : 4, Was ; " << s.rob(nums3) << endl;    

    return -1;
}





