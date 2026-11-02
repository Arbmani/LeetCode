#include "vector"
#include "iostream"
#include <climits>

using namespace std;

/**

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.


*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = INT_MAX, counter = 0;
        for (int num : nums) minval     = min(minval, num);
        for (int num : nums) counter   += (num - minval);
        return counter;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,1,1};


    cout << "Want : 3, Was : " << s.minMoves(nums1) << endl;
    cout << "Want : 0, Was : " << s.minMoves(nums2) << endl;

    return 0;
}