#include <ostream>
#include <unordered_map>
#include <vector>
#include "iostream"
#include "algorithm"
#include "unordered_map"
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

/**
[Medium Problem]

Given a set of distinct positive integers nums, 
return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


*/
class Solution {
public:
    vector<int> dfs(int index, vector<int>& nums, unordered_map<int, vector<int> >& hashMap){
        if (index == nums.size()) return {};
        if (hashMap.count(index)) return hashMap[index];


    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> hashMap;


        vector<int> ans;
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,3};
    vector<int> out1 = {1,2};
    vector<int> nums2 = {1,2,4,8};
    vector<int> out2 = {1,2,4,8};

    cout << "Want : " << out1 << ", Was : " << s.largestDivisibleSubset(nums1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.largestDivisibleSubset(nums2) << endl;


    return -1;
}