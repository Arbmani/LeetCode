#include "vector"
#include "unordered_map"
#include "iostream"


using namespace std;
/**
    Given an integer array "nums", and a "target" value,
    find the longest array/subarray that sums to target.
*/

class Solution {
public:
    int longest(const vector<int>& nums, int target) {
        int ans = 0, sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
            int want = sum - target;
            if (prefix.count(want)) ans = max(ans, index - prefix[want]);
            if (!prefix.count(sum)) prefix[sum] = index;          
        }

        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, -1, 0, 1, 1, -2};

    cout << "Want : 6, Was : " << s.longest(nums1, 0) << endl;


    return 0;
}


