#include <limits>
#include <vector>
#include <iostream>

using namespace std;

/**

[Easy Problem]

You are given an integer array nums.

Return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        float max1 = -numeric_limits<float>::infinity();
        float max2 = -numeric_limits<float>::infinity();
        float max3 = -numeric_limits<float>::infinity();
        bool int_min = false;
        for(int num : nums){
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num < max1 && num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num < max1 && num < max2 && num > max3){
                max3 = num;
            }
        }
        if(max3 != -numeric_limits<float>::infinity()) return static_cast<int>(max3);
        return static_cast<int>(max1); 
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {3,2,1};
    vector<int> nums2 = {1,2};
    vector<int> nums3 = {2,2,3,1};
    vector<int> nums4 = {1,2,-2147483648};

    cout << "Want : 1, Was : " << s.thirdMax(nums1) << endl;
    cout << "Want : 2, Was : " << s.thirdMax(nums2) << endl;
    cout << "Want : 1, Was : " << s.thirdMax(nums3) << endl;
    cout << "Want : -2147483648, Was : " << s.thirdMax(nums4) << endl;


    return -1;
}