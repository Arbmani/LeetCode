#include <csignal>
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;
#include "climits"

/**

[Hard Problem]

You are given an integer array nums of length n.

An integer k is called sortable if k divides n and you can sort nums 
in non-decreasing order by sequentially performing the following operations:

Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.


*/

// If len(n) is a prime, only k = 1 will work.
// Else find all k that can divide n.

class Solution {
public:
    bool isCyclicallySorted(const vector<int>& arr, int left, int right, int& minval, int& maxval){
        int n = right - left;
        if (n  < 1) throw invalid_argument("invalid array");
        int breaks = 0;
        for(int index = left; index < right; index++){
            minval = min(minval, arr[index]);
            maxval = max(maxval, arr[index]);
            int next = (index + 1 < right) ? index + 1 : left;

            if (arr[index] > arr[next]) breaks++;
            if (breaks > 1) return false;
        }
        return breaks <= 1;
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> divisors;
        for(int index = 1; index <= nums.size(); index++){
            if(nums.size() % index == 0) divisors.push_back(index);
        }
        vector<int> ans;
        for(int divisor: divisors){
            bool valid = true;
            int previous = INT_MIN;
            for(int index = 0; index + divisor <= nums.size(); index += divisor){
                int minval = INT_MAX;
                int maxval = INT_MIN;
                if (!isCyclicallySorted(nums, index, index + divisor, minval, maxval)){
                    valid = false;
                    break;
                
                }
                if(minval < previous){
                    valid = false;
                    break;
                }
                previous = maxval;
            }
            if (valid) ans.push_back(divisor);
        }
        int res = 0;
        for(int an: ans){
            res += an;
        }
        return res;
    }
};



int main(){
    Solution s;

    vector<int> nums1 = {3,1,2};
    vector<int> nums2 = {7,6,5};
    vector<int> nums3 = {5,8};

    cout << "Want : 3, Was : " << s.sortableIntegers(nums1) << endl;
    cout << "Want : 0, Was : " << s.sortableIntegers(nums2) << endl;
    cout << "Want : 3, Was : " << s.sortableIntegers(nums3) << endl;


    return -1;    
}