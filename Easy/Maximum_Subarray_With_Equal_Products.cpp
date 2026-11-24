#include "vector"
#include "iostream"
#include <numeric>

using namespace std;

/*

You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

-   prod(arr) is the product of all elements of arr.

-   gcd(arr) is the GCD of all elements of arr.

-   lcm(arr) is the LCM of all elements of arr.

Return the length of the longest product equivalent subarray of nums.

*/

class Solution {
public:
    int maxLength(vector<int>& nums){
        int best = 2, left = 0, product = 1;

        for (int right = 0; right < nums.size(); ++right){
            int num = nums[right];
            while (gcd(product, num) > 1) product /= nums[left++];
            product *= num;
            best     = max(best, right - left + 1);
        }

        return best;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2,1,2,1,1,1};
    vector<int> nums2 = {2,3,4,5,6};
    vector<int> nums3 = {1,2,3,1,4,5,1};

    cout << "\nWant : 5\nWas  : " << s.maxLength(nums1) << endl;
    cout << "\nWant : 3\nWas  : " << s.maxLength(nums2) << endl;
    cout << "\nWant : 5\nWas  : " << s.maxLength(nums3) << endl;

    return 0;
}