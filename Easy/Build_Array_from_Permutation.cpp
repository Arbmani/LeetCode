#include "vector"
#include "iostream"
#include <ostream>
#include <vector>

using namespace std;


/**
[Easy Problem]


Given a zero-based permutation nums (0-indexed), 
build an array ans of the same length where 
ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int index = 0; index < nums.size(); ++index) ans.push_back(nums[nums[index]]);
        return ans;      
    }
};


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    os << "[";
    for (int index = 0; index < v.size(); ++index){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}


int main(){
    Solution s;

    vector<int> nums1 = {0,2,1,5,3,4};
    vector<int> nums2 = {5,0,1,2,3,4};
    vector<int> outp1 = {0,1,2,4,5,3};
    vector<int> outp2 = {4,5,0,1,2,3};

    cout << "Want : " << outp1 << " Was : " <<  s.buildArray(nums1) << endl;
    cout << "Want : " << outp2 << " Was : " <<  s.buildArray(nums2) << endl;
    


    return -1;
}