#include <vector>
#include <iostream>

#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    /**
     *  [Easy Problem]
     *  
     *  You are given an integer array nums.
     * 
     *  Find three numbers whose product is maximum and return the maximum product.
     * 
     */


public:
    int maximumProduct(vector<int>& nums){
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int num : nums) {
            if (num >= max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num >= max2){
                max3 = max2;
                max2 = num;
            } else if (num > max3){
                max3 = num;
            }

            if (num <= min1){
                min2 = min1;
                min1 = num;
            } else if (num < min2){
                min2 = num;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};

int main(){

    Solution solution;

    vector<int> nums1 = {1,2,-3};
    vector<int> nums2 = {1,2,3,4};
    vector<int> nums3 = {-1,-2,-3};

    cout << "Want : - 6, Was : " << solution.maximumProduct(nums1) << endl;
    cout << "Want : +24, Was : " << solution.maximumProduct(nums2) << endl;
    cout << "Want : - 6, Was : " << solution.maximumProduct(nums3) << endl;



    return -1;
}