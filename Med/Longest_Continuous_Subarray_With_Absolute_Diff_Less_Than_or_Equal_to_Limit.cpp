#include "vector"
#include "iostream"

#include <deque>


using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQue;
        deque<int> maxQue;
        int left = 0;
        int ans  = 0;

        for (int right = 0; right < nums.size(); right++){
            while (!maxQue.empty() && nums[right] >= nums[maxQue.back()]) maxQue.pop_back();
            maxQue.push_back(right);
            while (!minQue.empty() && nums[right] <= nums[minQue.back()]) minQue.pop_back();
            minQue.push_back(right);
            
            
            while (nums[maxQue.front()] - nums[minQue.front()] > limit){
                if (maxQue.front() == left)  maxQue.pop_front();
                if (minQue.front() == left) minQue.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int>nums1 = {8, 2, 4, 7};
    vector<int>nums2 = {10, 1, 2, 4, 7, 2};
    vector<int>nums3 = {4, 2, 2, 2, 4, 4, 2, 2};

    cout << "\nWant : 2\nWas  : " << s.longestSubarray(nums1, 4) << endl;
    cout << "\nWant : 4\nWas  : " << s.longestSubarray(nums2, 5) << endl;
    cout << "\nWant : 3\nWas  : " << s.longestSubarray(nums3, 0) << endl;

    return 0;
}