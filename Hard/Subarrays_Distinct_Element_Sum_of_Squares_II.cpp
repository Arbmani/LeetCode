#include "vector"
#include "iostream"
#include <bitset>
#include <ostream>
#include <unordered_map>
#include <vector>
#include "cmath"

using namespace std;

/**

[Hard Problem]

You are given a 0-indexed integer array nums.

The distinct count of a subarray of nums is defined as:

Let nums[i..j] be a subarray of nums consisting of all the indices from i to j 
such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] 
is called the distinct count of nums[i..j].

Return the sum of the squares of distinct counts of all subarrays of nums.

Since the answer may be very large, return it modulo 10**9 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n               = nums.size();
        long long ans       = 0;
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> lastSeen;
        vector<long long> occurrenceCount(n + 1);
        vector<long long> previousIndexSum(n + 1);

        for(int right = 0; right < n; right++){
            int previous = lastSeen.count(nums[right]) ? lastSeen[nums[right]] : -1;
            long long count = 0;
            long long sum   = 0;

            for(int index = n - previous - 1; index > 0; index -= index & -index){
                count += occurrenceCount[index];
                sum   += previousIndexSum[index];
            }
            ans = (ans + (long long)(n - right) * ((long long)(right - previous) * (right - previous) - 2*(sum - previous * count))) % MOD;
            for(int index = n - previous; index <= n; index += index & -index){
                occurrenceCount[index]++;
                previousIndexSum[index] += previous;
            }
            lastSeen[nums[right]] = right;
        }
        return ans;
    }



    int sumCounts_slow(vector<int>& nums) {
        int modulo = 1000000007;
        int size = nums.size(), ans = 0;
        for(int index = 0; index < size; index++){
            bitset<100001> seen;
            for(int jhindex = index; jhindex < size; jhindex++){
                seen.set(nums[jhindex]);
                ans = (((seen.count() * seen.count() % modulo) + ans) % modulo);
            }
        }
        return ans;      
    }
};

template <typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for (int i = 0; i < v.size(); ++i){
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

int main(){
    vector<int> nums1 = {1,2,1};
    vector<int> nums2 = {2,2};
    Solution s;
    cout << "Want : 15 , Was : " << s.sumCounts(nums1)<< endl;
    cout << "Want :  3 , Was : " << s.sumCounts(nums2)<< endl;

    return -1;
}












