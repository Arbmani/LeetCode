#include "vector"
#include "iostream"
#include "stack"
#include "unordered_map"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int index = 0; index < vec.size(); index++){
        os << vec[index];
        if (index + 1 < vec.size()) os << ", ";
    }
    os << "]";
    
    return os;
}

/**

The next greater element of some element x in an array is 
the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, 
where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2){
            while (!st.empty() && num > st.top()){
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> res;
        for (int num : nums1){
            if (nextGreater.count(num)){
                res.push_back(nextGreater[num]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};


int main(){
    Solution s;

    vector<int> nums11 = {4,1,2};
    vector<int> nums12 = {1,3,4,2};
    vector<int> nums21 = {2,4};
    vector<int> nums22 = {1,2,3,4};


    vector<int> out1 = {-1,3,-1};
    vector<int> out2 = {3,-1};

    cout << "\nWant : " << out1 << ", \nWas  : " << s.nextGreaterElement(nums11, nums12) << endl;
    cout << "\nWant : " << out2 << ", \nWas  : " << s.nextGreaterElement(nums21, nums22) << endl;


    return 0;
}