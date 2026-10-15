#include "vector"
#include "iostream"
#include <vector>
#include "algorithm"
using namespace std;

/**
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.


*/

class Solution {
public:
    string largestNumber(vector<int>& nums){
        vector<string> strs;
        for(int num: nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](const string& num1, const string& num2){
            return num1 + num2 > num2 + num1;
        });
        if (strs[0] == "0") return "0";
        string result;
        for(const string& s: strs){
            result += s;
        }
        return result;
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {10, 2};
    vector<int> nums2 = {3,30,34,5,9};

    cout << "Want : 210, Was : " << s.largestNumber(nums1) << endl;
    cout << "Want : 9534330, Was : " << s.largestNumber(nums2) << endl;


    return  -1;
}