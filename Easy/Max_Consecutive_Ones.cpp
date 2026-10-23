#include "vector"
#include "iostream"

using namespace std;

/**

Given a binary array nums, return the maximum number of consecutive 1's in the array.

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, len = 0;
        for(int index = 0; index < nums.size(); index++){
            if (nums[index] == 1) len++;
            else len = 0;
            ans = max(ans, len);
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,1,0,1,1,1};
    vector<int> nums2 = {1,0,1,1,0,1};

    cout << "Want : 3, Was : " << s.findMaxConsecutiveOnes(nums1) << endl;
    cout << "Want : 2, Was : " << s.findMaxConsecutiveOnes(nums2) << endl;

    return -1;
} 