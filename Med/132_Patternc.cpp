#include "vector"
#include "iostream"
#include <climits>
#include <ios>

using namespace std;

/**

Given an array of n integers nums, a 132 pattern is a subsequence of three integers 
nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> stac;
        long long second = LLONG_MIN;

        for (int i = nums.size() -1; i >= 0; i--){
            if (nums[i] < second) return true;
            while(!stac.empty() && nums[i] > stac.back()){
                second = stac.back();
                stac.pop_back();
            }
            stac.push_back(nums[i]);
        }

        return false;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {3,1,4,2};
    vector<int> nums3 = {-1,3,2,0};

    cout << "\nWant : false\nWas  : " << boolalpha << s.find132pattern(nums1) << endl;
    cout << "\nWant : true\nWas  : " << boolalpha << s.find132pattern(nums2) << endl;
    cout << "\nWant : true\nWas  : " << boolalpha << s.find132pattern(nums3) << endl;

    return 0;
}