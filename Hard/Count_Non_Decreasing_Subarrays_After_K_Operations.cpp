#include "vector"
#include "iostream"
#include "deque"

using namespace std;

/**

You are given an array nums of n integers and an integer k.

For each subarray of nums, you can apply up to k operations on it. 
In each operation, you increment any element of the subarray by 1.

Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.

An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.


*/

class Solution {
private:
    struct Group {
        long long value;
        long long count;
    };

public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        deque<Group> que;
        long long   ans     = 0;
        long long   cost    = 0;
        int         end   = nums.size() - 1;
        
        for (int start = nums.size() - 1; start >= 0; start--){
            long long count = 1;
            long long num   = nums[start];
            while (!que.empty() && que.front().value <= num){
                cost  += (num - que.front().value) * que.front().count;
                count += que.front().count;
                que.pop_front(); 
            }
            que.push_front({num, count});
            while (cost > k){
                cost -= que.back().value - nums[end];
                que.back().count--;
                if (que.back().count == 0) que.pop_back();
                end--;
            }
            ans += end - start + 1;
        }
        return ans;
    }
};

int main(){
    Solution s;


    vector<int> nums1 = {6,3,1,2,4,4};
    vector<int> nums2 = {6,3,1,3,6};

    vector<int> nums3 = {1000000000,1};

    cout << "\nWant : 17\nWas  : " << s.countNonDecreasingSubarrays(nums1, 7) << endl;
    cout << "\nWant : 12\nWas  : " << s.countNonDecreasingSubarrays(nums2, 4) << endl;

    cout << "\nWant : 2\nWas  : " << s.countNonDecreasingSubarrays(nums3, 999999998) << endl;

    return 0;
}