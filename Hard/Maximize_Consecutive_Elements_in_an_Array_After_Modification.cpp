#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"


using namespace std;

/*

You are given a 0-indexed array nums consisting of positive integers.

Initially, you can increase the value of any element in the array by at most 1.

After that, you need to select one or more elements from the final 
array such that those elements are consecutive when sorted in increasing order. 
For example, the elements [3, 4, 5] are consecutive while [3, 4, 6] and [1, 1, 2, 3] are not.

Return the maximum number of elements that you can select.


*/

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;

        for (int num : nums){
            dp[num + 1] = dp[num]     + 1;
            dp[num]     = dp[num - 1] + 1;
            ans         = max({ans, dp[num], dp[num + 1]});
        }
        return ans;
    }
};


int main(){
    Solution s = Solution();

    vector<int> nums1 = {2, 1, 5, 1, 1};
    vector<int> nums2 = {1, 4, 7, 10};
    
    
    vector<int> nums3 = {1, 1, 1, 3};



    cout << "\nWant : 3\nWas  : " << s.maxSelectedElements(nums1) << endl;
    cout << "\nWant : 1\nWas  : " << s.maxSelectedElements(nums2) << endl;

    cout << "\nWant : 3\nWas  : " << s.maxSelectedElements(nums3) << endl;

    return 0; 
}