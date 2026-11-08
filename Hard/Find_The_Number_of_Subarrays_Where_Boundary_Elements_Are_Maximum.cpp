#include "vector"
#include "iostream"

using namespace std;

/**

You are given an array of positive integers nums.

Return the number of subarrays of nums, where the first 
and the last elements of the subarray are equal to the 
largest element in the subarray.


*/

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int, long long>> stac;
        long long ans = 0;
        for (int num : nums){
            while (!stac.empty() && stac.back().first < num) stac.pop_back();
            ans++;
            if (!stac.empty() && stac.back().first == num){
                ans += stac.back().second;
                stac.back().second++;
            }
            else    stac.push_back({num, 1});
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, 4, 3, 3 ,2};
    vector<int> nums2 = {3, 3, 3};
    vector<int> nums3 = {1};


    cout << "\nWant : 6\nWas  : " << s.numberOfSubarrays(nums1) << endl;
    cout << "\nWant : 6\nWas  : " << s.numberOfSubarrays(nums2) << endl;
    cout << "\nWant : 1\nWas  : " << s.numberOfSubarrays(nums3) << endl;

    return 0;
}