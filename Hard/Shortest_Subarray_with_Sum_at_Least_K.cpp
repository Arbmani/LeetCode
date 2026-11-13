#include "vector"
#include "iostream"
//#include "unordered_map"
#include "deque"
#include "algorithm"
#include <climits>


using namespace std;

/**

Given an integer array nums and an integer k, 
return the length of the shortest non-empty subarray 
of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.


*/

//class Solution_cantWork {
//public:
//    int shortestSubarray(vector<int>& nums, int k) {
//        unordered_map<int, int> prefixSum;
//        prefixSum[0] = nums.size();
//        int sum      = 0;
//        int ans      = nums.size() + 1;
//        for (int i = nums.size() - 1; i >= 0; i--){
//            sum += nums[i];
//            if (prefixSum.count(sum - k)) ans = min(ans, prefixSum[sum - k] - i); 
//            prefixSum[sum] = i;
//            
//        }
//
//        return ans == (nums.size() + 1) ? -1 : ans;
//    }
//};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int         n   = nums.size();
        int         ans = INT_MAX;
        deque<int>  que;
        vector<long long>           prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        
        for (int i = 0; i <= n; i++){
            while(!que.empty() && prefix[i] - prefix[que.front()] >= k){
                ans = min(ans, i - que.front());
                que.pop_front();
            }
            while(!que.empty() && prefix[i] <= prefix[que.back()]) que.pop_back();
            que.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1};
    vector<int> nums2 = {1,2};
    vector<int> nums3 = {2, -1, 2};

    vector<int> nums4 = {2, 1,-1,  -2};


    cout << "\nWant : 1\nWas  : " << s.shortestSubarray(nums1, 1) << endl;
    cout << "\nWant : -1\nWas  : " << s.shortestSubarray(nums2, 4) << endl;
    cout << "\nWant : 3\nWas  : " << s.shortestSubarray(nums3, 3) << endl;

    cout << "\nWant : 1\nWas  : " << s.shortestSubarray(nums4, 0) << endl;
 
    return 0;
}