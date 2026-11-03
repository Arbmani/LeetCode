#include "vector"
#include "iostream"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i < vec.size() -1) os << ", ";
    }
    os << "]";

    return os;
}

/**
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (n == 0) return ans;
        vector<int> monoStack;
        monoStack.reserve(n);
        for (int index = 0; index < 2 * n; index++){
            int idx = index % n;
            while(!monoStack.empty() && nums[idx] > nums[monoStack.back()]){
                int prevIndex = monoStack.back();
                monoStack.pop_back();
                ans[prevIndex] = nums[idx];
            }
            if (index < n) monoStack.push_back(idx);
        }
        return ans;   
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,1};
    vector<int> nums2 = {1,2,3,4,3};

    vector<int> out1 = {2,-1,2};
    vector<int> out2 = {2,3,4,-1,4};


    cout << "\nWant : " << out1 << ",\nWas  : " << s.nextGreaterElements(nums1) << endl;
    cout << "\nWant : " << out2 << ",\nWas  : " << s.nextGreaterElements(nums2) << endl;

    return 0;
}