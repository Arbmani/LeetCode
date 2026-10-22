#include <vector>
#include "iostream"
#include "algorithm"
using namespace std;

/**

[Medium Problem]


You are given an integer array nums of length n, 
where nums is a permutation of the integers from 0 to n - 1.

You may perform only the following operations:

-   Reverse the entire array.

-   Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the minimum number of operations required to sort the array in increasing order. 
If it is not possible to sort the array using only the given operations, return -1.

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n           = nums.size();
        int zeroIndex   = 0;

        for(int index = 0; index < n; index++){
            if (nums[index] == 0){
                zeroIndex = index;
                break;
            }
        }
        auto getValue = [&](int k) {
            return nums[(zeroIndex + k) % n];
        };
        bool increasing = true;
        bool decreasing = true;


        for(int k = 0; k < n; k++){
            if(getValue(k) != k)            increasing = false;
            if(getValue(k) != ((n - k) % n))  decreasing = false;
        }
        if (increasing) return min(zeroIndex, n - zeroIndex + 2);
        if (decreasing) return min(zeroIndex + 2, n - zeroIndex);
        return -1;
    }
};



int main(){
    Solution s;

    vector<int> nums1 = {0,2,1};
    vector<int> nums2 = {1,0,2};
    vector<int> nums3 = {2,0,1,3};

    cout << "Want :  2, Was : " << s.minOperations(nums1) << endl;
    cout << "Want :  2, Was : " << s.minOperations(nums2) << endl;
    cout << "Want : -1, Was : " << s.minOperations(nums3) << endl;


    return -1;
}