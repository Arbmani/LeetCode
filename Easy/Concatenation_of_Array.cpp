#include "vector" 

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size(), 0);
        for (int index = 0; index < nums.size(); index ++){
            ans[index] = nums[index];
            ans[index + nums.size()] = nums[index];
        }
        return ans;
    }
};