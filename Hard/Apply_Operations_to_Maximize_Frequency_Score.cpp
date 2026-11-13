#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/**

You are given a 0-indexed integer array nums and an integer k.

You can perform the following operation on the array at most k times:

-   Choose any index i from the array and increase or decrease nums[i] by 1.

The score of the final array is the frequency of the most frequent element in the array.

Return the maximum score you can achieve.

The frequency of an element is the number of occurences of that element in the array.

*/


class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        int left = 0;
        int ans  = 1;

        for (int right = 0; right < n; right++){
            while (left <= right){
                int mid = (left + right) / 2;

                long long median    = nums[mid];
                long long leftCost  = median * (mid - left) - (prefix[mid] - prefix[left]);
                long long rightCost = (prefix[right + 1] - prefix[mid + 1]) - median * (right - mid);
                long long totalCost = leftCost + rightCost;
                if (totalCost <= k) break;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, 2, 6, 4};
    vector<int> nums2 = {1, 4, 4, 2, 4};

    cout << "\nWant : 3\nWas  : " << s.maxFrequencyScore(nums1, 3) << endl;
    cout << "\nWant : 3\nWas  : " << s.maxFrequencyScore(nums2, 0) << endl;

    return 0;
}