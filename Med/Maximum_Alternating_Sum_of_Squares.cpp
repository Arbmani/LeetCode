#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    /**
        [Medium Problem]

            You are given an integer array nums. You may rearrange the elements in any order.

            The alternating score of an array arr is defined as:

            -   score = arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + ...

            Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
    
     */


public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if (i < nums.size() / 2) ans -= nums[i] * nums[i];
            else                     ans += nums[i] * nums[i];
        }
        return ans;
    }
};

int main(){

    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,-1,2,-2,3,-3};
    Solution s;

    cout << "Want : 12, Was : " << s.maxAlternatingSum(nums1) << endl;
    cout << "Want : 16, Was : " << s.maxAlternatingSum(nums2) << endl;

    return -1;
}


