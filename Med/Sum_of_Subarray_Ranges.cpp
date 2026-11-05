#include "vector"
#include "stack"
#include "iostream"

using namespace std;

/**

You are given an integer array nums. 
The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


*/

class Solution {
private:
    long long calculateSum(const vector<int>& nums, bool findMax){
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> stac;

        for (int i = 0; i < n; ++i){
            while(!stac.empty() && 
                (findMax 
                    ? nums[stac.top()] <= nums[i]
                    : nums[stac.top()] >= nums[i])) stac.pop();
            left[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }
        while (!stac.empty()) stac.pop();
        for (int i = n - 1; i >= 0; --i){
            while(!stac.empty() &&
                (findMax
                    ? nums[stac.top()] < nums[i]
                    : nums[stac.top()] > nums[i])) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++){
            long long count = (long long)(i - left[i])*(right[i] - i);
            ans += count * nums[i];
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return calculateSum(nums, true) - calculateSum(nums, false);
    }
};



class Solution_ass {
private:
    long long sumMax(const vector<int>& nums){
        int n = nums.size();
        stack<int> stac;
        vector<int> left(n), right (n);
        for (int i = 0; i < n; i++){
            while(!stac.empty() && nums[stac.top()] <= nums[i]) stac.pop();
            left[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }
        while(!stac.empty()) stac.pop();
        for (int i = n - 1; i >= 0; --i){
            while(!stac.empty() && nums[stac.top()] < nums[i]) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++){
            long long count = (long long)(i - left[i]) * (right[i] - i);
            ans += count * nums[i];
        }
        return ans;
    }
    long long sumMin(const vector<int>& nums){
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> stac;

        for(int i = 0; i < n; i++){
            while(!stac.empty() && nums[stac.top()] >= nums[i]) stac.pop();
            left[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }
        while(!stac.empty()) stac.pop();
        for (int i = n -1; i >= 0; i--){
            while(!stac.empty() && nums[stac.top()] > nums[i]) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        long long ans= 0;
        for(int i = 0; i < n; ++i){
            long long count = (long long)(i - left[i]) * (right[i] - i);
            ans += count * nums[i];
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,3,3};
    vector<int> nums3 = {4,-2,-3,4,1};

    cout << "\nWant : 4\nWas  : " << s.subArrayRanges(nums1) << endl;
    cout << "\nWant : 4\nWas  : " << s.subArrayRanges(nums2) << endl;
    cout << "\nWant : 59\nWas  : " << s.subArrayRanges(nums3) << endl;

    return 0;
}