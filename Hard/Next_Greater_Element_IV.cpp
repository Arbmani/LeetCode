#include "vector"
#include "iostream"
#include "stack"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if ( i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    
    return os;
}

/*

You are given a 0-indexed array of non-negative integers nums. 
For each integer in nums, you must find its respective second greater integer.

The second greater integer of nums[i] is nums[j] such that:

j > i
nums[j] > nums[i]
There exists exactly one index k such that nums[k] > nums[i] and i < k < j.
If there is no such nums[j], the second greater integer is considered to be -1.

For example, in the array [1, 2, 4, 3], the second greater integer of 1 is 4, 2 is 3, and that of 3 and 4 is -1.
Return an integer array answer, where answer[i] is the second greater integer of nums[i]


*/

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, - 1);
        stack<int> first, second;
        for (int i = 0; i < n; i++){
            while (!second.empty() && nums[second.top()] < nums[i]){
                ans[second.top()] = nums[i];
                second.pop();
            }
            vector<int> temp;
            while (!first.empty() && nums[first.top()] < nums[i]){
                temp.push_back(first.top());
                first.pop();
            }
            for (int j = temp.size() - 1; j >= 0; j--){
                second.push(temp[j]);
            }
            first.push(i);
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {2,4,0,9,6};
    vector<int> nums2 = {3, 3};

    vector<int> out1 = {9,6,6,-1 , -1};
    vector<int> out2 = {-1, -1};


    cout << "\nWant : " << out1 << "\nWas  : " << s.secondGreaterElement(nums1) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.secondGreaterElement(nums2) << endl;


    return 0;
}
