#include "vector"
#include "iostream"
#include <climits>
using namespace std;

/**
[Medium Problem]

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. 
We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long F   = 0;

        for(int index = 0; index < n; index++){
            sum += nums[index];
            F   += 1LL * index * nums[index];
        }
        long long maxVal = F;
        for(int k = 1; k < n; k++){
            F = F + sum - 1LL * n * nums[n-k];
            maxVal = max(maxVal, F);
        }
        return static_cast<int>(maxVal);

    }
};


int main(){
    Solution s;

    vector<int> nums1 = {4,3,2,6};
    vector<int> nums2 = {100};
    cout << "Want : 26, Was : " << s.maxRotateFunction(nums1) << endl;
    cout << "Want : 0, Was : " << s.maxRotateFunction(nums2) << endl;

    return -1;
}