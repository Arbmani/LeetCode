#include "vector"
#include "iostream"
#include "cmath"
#include "unordered_map"


using namespace std;

/**

You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

-   i != j,

-   abs(i - j) <= indexDiff.

-   abs(nums[i] - nums[j]) <= valueDiff, and

Return true if such pair exists or false otherwise.


*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;
        unordered_map<long long, long long> buckets;
        const long long                     bucketsWidth = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++){
            long long num       = nums[i];
            long long bucket_ID = num >= 0 ? num / bucketsWidth : ((num + 1) / bucketsWidth) - 1;
            if (buckets.count(bucket_ID)) return true;
            if (buckets.count(bucket_ID - 1) && num - buckets[bucket_ID - 1] <= valueDiff) return true;
            if (buckets.count(bucket_ID + 1) && buckets[bucket_ID + 1] - num <= valueDiff) return true;
            buckets[bucket_ID] = num;
            if (i >= indexDiff){
                long long expiredNum        = nums[i - indexDiff];
                long long expired_bucket_id = expiredNum >= 0 ? expiredNum / bucketsWidth : ((expiredNum + 1) / bucketsWidth) - 1;
                buckets.erase(expired_bucket_id);
            }
        }

        return false;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,2, 3,1};
    vector<int> nums2 = {1, 5, 9, 1, 5, 9};

    cout << "\nWant : true\nWas  : " << boolalpha << s.containsNearbyAlmostDuplicate(nums1, 3, 0) << endl; 
    cout << "\nWant : false\nWas  : " << boolalpha << s.containsNearbyAlmostDuplicate(nums2, 2, 3) << endl; 


    return 0;
}