#include "vector"
#include "iostream"
#include <climits>

using namespace std;

/**

You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

-   Choose an integer i such that 1 <= i < n and nums[i] > 0.
-   Decrease nums[i] by 1.
-   Increase nums[i - 1] by 1.

Return the minimum possible value of the maximum integer of nums after performing any number of operations.


*/


class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        long long ans = INT_MIN;
        for(int index = 0; index < nums.size(); index++){
            sum += nums[index];
            ans = max(ans, (sum + index) / (index + 1));
        }

        return static_cast<int>(ans);
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {3,7,1,6};
    vector<int> nums2 = {10,1};

    cout << "Want : 5,  Was : " << s.minimizeArrayValue(nums1) << endl;
    cout << "Want : 10, Was : " << s.minimizeArrayValue(nums2) << endl;

    return 0;
}