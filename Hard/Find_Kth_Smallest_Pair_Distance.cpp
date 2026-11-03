#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/**

The distance of a pair of integers a and b is defined 
as the absolute difference between a and b.

Given an integer array nums and an integer k, 
return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.


*/

class Solution {
private:
    int countPairs(vector<int>& nums, int maxDist){
        int left = 0, count = 0;
        for (int right = 0; right < nums.size(); right++){
            while (nums[right] - nums[left] > maxDist) left++;
            count += right - left;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        while (low < high){
            int mid     = low + (high - low) / 2;
            int pairs   = countPairs(nums, mid);
            
            if (pairs >= k) high = mid;
            else            low  = mid + 1; 
        }
        return low;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,3,1};
    vector<int> nums2 = {1,1,1};
    vector<int> nums3 = {1,6,1};

    cout << "Want : 0, Was : " << s.smallestDistancePair(nums1, 1) << endl;
    cout << "Want : 0, Was : " << s.smallestDistancePair(nums2, 2) << endl;
    cout << "Want : 5, Was : " << s.smallestDistancePair(nums3, 3) << endl;


    return 0;
}