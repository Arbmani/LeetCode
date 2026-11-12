#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

/**

You are given an array of integers nums. 
Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) { 
        int inc = 1, dec = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++){
            int cur = nums[i], prev = nums[i - 1];
            if (cur > prev){
                inc++;
                dec = 1;
            } else if (cur < prev){
                inc = 1;
                dec++;
            } else{
                inc = dec = 1;
            }
            ans = max({ans, inc, dec});
        }
        return ans;
    }


    int longestMonotonicSubarray_ugly(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int ans = 1, stacTop = nums[0], stacSize = 1, flag = 0;

        for (int i = 1; i < n; i++){
            int num = nums[i];
            if ((flag == 1 || flag == 0) && num > stacTop){
                stacSize++;
                flag = 1;
            } else if ((flag == -1 || flag == 0) && num < stacTop){
                stacSize++;
                flag = -1;
            } else if (num == stacTop) {
                stacSize = 1;
                flag     = 0;
            } 
            else{
                stacSize    = 2;
                flag        = (num > stacTop) ? 1 : -1;
            }
            stacTop = num;
            ans     = max(ans, stacSize);
        }
        
        return ans;
    }


    int longestMonotonicSubarray_slow(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        stack<pair<int, int>> stac;
        stac.push({nums[0], 0});
        int ans = 0;
        for (int i = 1; i < n; i++){
            auto& [top, flag] = stac.top();
            if ((flag == 1 || flag == 0) && nums[i] > top) stac.push({nums[i], 1});
            else if ((flag == -1 || flag == 0) && nums[i] < top) stac.push({nums[i], -1});
            else{
                ans = max(ans, (int)stac.size());
                while (!stac.empty()) stac.pop();
                stac.push({nums[i], 0});
            }

        }
        if (!stac.empty()) ans = max(ans, (int)stac.size());


        
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,4,3,3,2};
    vector<int> nums2 = {3,3,3,3};
    vector<int> nums3 = {3,2 ,1};

    cout << "\nWant : 2\nWas  : " << s.longestMonotonicSubarray(nums1) << endl;
    cout << "\nWant : 1\nWas  : " << s.longestMonotonicSubarray(nums2) << endl;
    cout << "\nWant : 3\nWas  : " << s.longestMonotonicSubarray(nums3) << endl;



    return 0;
}