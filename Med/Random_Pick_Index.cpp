#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

/**
Given an integer array nums with possible duplicates, 
randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. 
If there are multiple valid i's, then each index should have an equal probability of returning.



*/

class Solution {
public:
    unordered_map<int, vector<int>> hashMap;
    random_device rd;
    mt19937 gen{rd()};

    Solution(vector<int>& nums) {
        for(int index = 0; index < nums.size(); index++){
            hashMap[nums[index]].push_back(index);
        }
        
    }
    
    int pick(int target) {
        auto vec = hashMap[target];
        uniform_int_distribution<int> dis(0, vec.size() - 1);
        return vec[dis(gen)];

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

 int main(){
    return -1;
 }