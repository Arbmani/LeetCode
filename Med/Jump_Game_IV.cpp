#include "vector"
#include "iostream"

#include "deque"

using namespace std;

/**

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, 
you can jump at most k steps forward without going outside the boundaries of the array. 
That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). 
Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.


*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> max;
        dp[0] = nums[0];
        max.push_back(0);

        for (int i = 1; i < n; i++){
            while (!max.empty() && max.front() < i - k) max.pop_front();
            dp[i] = nums[i] + dp[max.front()];
            while (!max.empty() && dp[i] >= dp[max.back()]) max.pop_back();
            max.push_back(i);
        }
        return dp[n - 1];      
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,-1,-2,4,-7,3};
    vector<int> nums2 = {10,-5,-2,4,0,3};
    vector<int> nums3 = {1,-5,-20,4,-1,3,-6,-3};

    cout << "\nWant : 7\nWas  : " << s.maxResult(nums1, 2) << endl;
    cout << "\nWant : 17\nWas  : " << s.maxResult(nums2, 3) << endl;
    cout << "\nWant : 0\nWas  : " << s.maxResult(nums3, 2) << endl;

    return 0;
}
