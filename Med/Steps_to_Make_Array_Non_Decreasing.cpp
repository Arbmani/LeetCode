
#include "iostream"

#include <vector>
#include <stack>


using namespace std;

/**

You are given a 0-indexed integer array nums. 
In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.


*/

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> stac;
        int ans = 0;

        for (int num : nums){
            int steps = 0;
            while(!stac.empty() && stac.top().first <= num){
                steps = max(steps, stac.top().second);
                stac.pop();
            }
            if (!stac.empty())  steps++;
            else                steps = 0;
            ans = max(ans, steps);
            stac.push({num, steps});
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {5,3,4,4,7,3,6,11,8,5,11};
    vector<int> nums2 = {4,5,7,7,13};

    cout << "\nWant : 3\nWas  : " << s.totalSteps(nums1) << endl; 
    cout << "\nWant : 0\nWas  : " << s.totalSteps(nums2) << endl; 

    return 0;
}