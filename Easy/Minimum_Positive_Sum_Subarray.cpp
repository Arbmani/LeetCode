#include "vector"
#include "iostream"
#include "set"
#include "climits"
#include <climits>

using namespace std;

/**

You are given an integer array nums and two integers l and r. 
Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.

Return the minimum sum of such a subarray. If no such subarray exists, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];
        multiset<long long> active;
        long long ans = LLONG_MAX;

        for (int i = l; i <= n; i++){
            active.insert(prefixSum[i - l]);
            if (i - r - 1 >= 0){
                auto it = active.find(prefixSum[i -r - 1]);
                if (it != active.end()) active.erase(it);
            }   
            auto it = active.lower_bound(prefixSum[i]);
            if (it == active.begin()) continue;
            --it;
            ans = min(ans, prefixSum[i] - *it);
        }
        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};


int main (){
    Solution s;

    vector<int>nums1 = {3, -2, 1, 4};
    vector<int>nums2 = {-2, 2, -3, 1};
    vector<int>nums3 = {1, 2, 3, 4};

    cout <<"\nWant : 1\nWas  : " << s.minimumSumSubarray(nums1, 2, 3) << endl;
    cout <<"\nWant : -1\nWas  : " << s.minimumSumSubarray(nums2, 2, 3) << endl;
    cout <<"\nWant : 3\nWas  : " << s.minimumSumSubarray(nums3, 2, 4) << endl;

    return 0;
}