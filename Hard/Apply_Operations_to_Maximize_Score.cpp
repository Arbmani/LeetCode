#include "vector"
#include "algorithm"
#include "stack"

#include "iostream"

using namespace std;

/** 

You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

-   Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.

-   Choose an element x of nums[l, ..., r] with the highest prime score. 
    If multiple such elements exist, choose the one with the smallest index.

-   Multiply your score by x.

Here, nums[l, ..., r] denotes the subarray of nums starting at index l and 
ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime 
factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

*/

class Solution {
private:
    static constexpr long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp){
        long long ans = 1;
        while (exp > 0){
            if (exp & 1) ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }


public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> primeScore(maxVal + 1, 0);
        for (int p = 2; p <= maxVal; p++){
            if (primeScore[p] == 0){
                for (int j = p; j <= maxVal; j+=p){
                    primeScore[j]++;
                }
            }
        }
        vector<long long> prev(n, -1);
        stack<int> stac;

        for (int i = 0; i < n; i++){
            while(!stac.empty() && primeScore[nums[stac.top()]] < primeScore[nums[i]]) stac.pop();
            if   (!stac.empty()) prev[i] = stac.top();
            stac.push(i);
        }

        vector<long long> next(n, n);
        while (!stac.empty()) stac.pop();

        for (int i = n - 1; i >= 0; i--){
            while (!stac.empty() && primeScore[nums[stac.top()]] <= primeScore[nums[i]]) stac.pop();
            if (!stac.empty()) next[i] = stac.top();
            stac.push(i);
        }

        vector<long long> count(n);
        for (int i = 0; i < n; i++) count[i] = (i - prev[i]) * (next[i] - i);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), 
            [&](int a, int b){
                return nums[a] > nums[b];
            });
        long long ans = 1;
        for (int i : indices){
            if (k == 0) break;
            long long operation = min(count[i], (long long) k);
            ans = ans * modPow(nums[i], operation) % mod;
            k -= operation;
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {8, 3, 9, 3, 8};
    vector<int> nums2 = {19, 12, 14, 6, 10, 18};

    cout << "\nWant : 81\nWas  : " << s.maximumScore(nums1, 2) << endl;
    cout << "\nWant : 4788\nWas  : " << s.maximumScore(nums2, 3) << endl;

    return 0;
}