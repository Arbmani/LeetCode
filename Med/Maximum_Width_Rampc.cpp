#include "vector"
#include "stack"
#include "iostream"

using namespace std;

/**

A ramp in an integer array nums is a pair (i, j) 
for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum 
width of a ramp in nums. If there is no ramp in nums, return 0.

*/

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stac;
        for (int i = 0; i < nums.size(); i++){
            if (stac.empty() || nums[i] < nums[stac.top()]) stac.push(i);
        }   
        int ans = 0;
        for (int j = nums.size() - 1; j >= 0; j--){
            if(stac.empty()) break;
            while(!stac.empty() && nums[j] >= nums[stac.top()]){
                ans = max(ans, j - stac.top());
                stac.pop();
            }
        }
        return ans;        
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {6, 0, 8, 2, 1, 5};
    vector<int> nums2 = {9,8,1,0,1,9,4,0,4,1};

    cout << "\nWant : 4\nWas  : " << s.maxWidthRamp(nums1) << endl;
    cout << "\nWant : 7\nWas  : " << s.maxWidthRamp(nums2) << endl;

    return 0;
}