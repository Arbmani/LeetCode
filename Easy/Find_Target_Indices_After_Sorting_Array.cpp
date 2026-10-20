#include <ostream>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

/**

[Easy Problem]

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. 
If there are no target indices, return an empty list. The returned list must be sorted in increasing order.



*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans = {};
        int lesser_count = 0;
        int target_count = 0;

        for (int num : nums){
            if (num < target) lesser_count++;
            else if (num == target) target_count++;
        }
        for(int index = lesser_count; index < lesser_count + target_count; index++){
            ans.push_back(index);
        }
        return ans;
    }
};
template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";

    return os;
}

int main(){
    Solution s;
    vector<int> nums1 = {1,2,5,2,3};
    vector<int> nums2 = {1,2,5,2,3};
    vector<int> nums3 = {1,2,5,2,3};

    vector<int> ou1 = {1,2};
    vector<int> ou2 = {3};
    vector<int> ou3 = {4};
    


    cout << "Want : " << ou1 << ", Was : " << s.targetIndices(nums1, 2) << endl;
    cout << "Want : " << ou2 << ", Was : " << s.targetIndices(nums2, 3) << endl;
    cout << "Want : " << ou3 << ", Was : " << s.targetIndices(nums3, 5) << endl;

    return -1;
}