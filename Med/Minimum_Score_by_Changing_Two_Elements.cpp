#include "vector"
#include "iostream"
#include "algorithm"
#include <climits>

using namespace std;

/**

You are given an integer array nums.

-   The low score of nums is the minimum absolute difference between any two integers.

-   The high score of nums is the maximum absolute difference between any two integers.

-   The score of nums is the sum of the high and low scores.

Return the minimum score after changing two elements of nums.


*/
class Solution {
public:
    // 3 cases, (all cases leads low score to 0)
    //  set min and max to mid 
    //  set 2 min       to mid
    //  set 2 max       to mid 

    int minimizeSum(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int num : nums){
            if (num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2){
                max3 = max2;
                max2 = num;
            } else if (num > max3) max3 = num;

            if (num < min1){
                min3 = min2;
                min2 = min1;
                min1 = num;
            } else if (num < min2){
                min3 = min2;
                min2 = num;
            } else if (num < min3) min3 = num;
        }
        return min({max3 - min1, max1 - min3, max2 - min2});
    }
};


class Solution_slow {
public:
    // 3 cases, (all cases leads low score to 0)
    //  set min and max to mid 
    //  set 2 min       to mid
    //  set 2 max       to mid 

    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n   = nums.size() - 1;
        return min({nums[n - 2] - nums[0],nums[n] - nums[2], nums[n - 1] - nums[1]});
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, 4, 7, 8, 5};
    vector<int> nums2 = {1, 4, 3};
    cout << "\nWant : 3\nWas  : " << s.minimizeSum(nums1) << endl;
    cout << "\nWant : 0\nWas  : " << s.minimizeSum(nums2) << endl;

    return 0;
}