#include "vector"
#include "stack"
#include "iostream"

using namespace std;

/**

The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

-   For example, the array [3,2,5] (minimum value is 2) 
    has a min-product of 2 * (3+2+5) = 2 * 10 = 20.

Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. 
Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before 
performing the modulo operation. Testcases are generated 
such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.


*/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long mod = 1e9 + 7;
        int n = nums.size();

        stack<int> stac;
        vector<int> left(n), right(n);
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        for (int i = 0; i < n; i++){
            while(!stac.empty() && nums[stac.top()] >= nums[i]) stac.pop();
            left[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }
        while(!stac.empty()) stac.pop();
        for (int i = n - 1; i >= 0; i--){
            while(!stac.empty() && nums[stac.top()] > nums[i]) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++){
            long long subarray = prefix[right[i]] - prefix[left[i] + 1];
            ans = max(ans, subarray * nums[i]);
        }
        return ans % mod;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,3,2};
    vector<int> nums2 = {2,3,3,1,2};
    vector<int> nums3 = {3,1,5,6,4,2};

    cout << "\nWant : 14\nWas  : " << s.maxSumMinProduct(nums1) << endl;
    cout << "\nWant : 18\nWas  : " << s.maxSumMinProduct(nums3) << endl;
    cout << "\nWant : 60\nWas  : " << s.maxSumMinProduct(nums2) << endl;


    return 0;
}

