#include "vector"
#include "unordered_map"
#include "iostream"
#include <climits>
#include <unordered_map>

using namespace std;

/*

You are given an integer array nums.

Find the minimum length of a subarray 
that is not identical to any other subarray in nums.

Return an integer denoting the 
minimum possible length of such a subarray.

Two subarrays are considered identical if 
they have the same length and the same elements in corresponding positions.


*/

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> windowIds{nums};
        for (int half = 1; 2 * half <= n; half *= 2){
            unordered_map<long long, int> ids;
            vector<int> currentIds;
            const vector<int>& prev = windowIds.back();
            for (int i = 0; i + half < (int)prev.size(); i++){
                int leftId  = prev[i];
                int rightId = prev[i + half];
                long long key = ((long long)leftId << 32) | rightId; 
                currentIds.push_back(ids.try_emplace(key, ids.size()).first->second);
            }
            windowIds.push_back(std::move(currentIds));
        }

        auto found = [&](int length) {
            int k = 0;
            while ((1 << (k + 1)) <= length) k++;
            int blockLength = 1 << k;
            int offset = length - blockLength;
            unordered_map<long long, int> frequency;

            for (int i = 0; i + length <= n; i++){
                int leftId  = windowIds[k][i];
                int rightId = windowIds[k][i + offset];
                long long key = ((long long)leftId << 32) |rightId;
                frequency[key]++; 
            }
            for (auto& entry : frequency){
                if (entry.second == 1) return true;
            }
            return false;
        };

        int low = 1, high = n;

        while (low < high){
            int mid = low + (high - low) / 2;
            if (found(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

// 7, 7, 7, 1, 6, 7, 7, 7, 7, 7, 1, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 

// 1, 2, 3, 1, 2, 3, 1, 2, 3


int main(){
    Solution s;

    vector<int> nums1 = {3,3,3};
    vector<int> nums2 = {2,1,2,3,3};
    vector<int> nums3 = {1,1,2,2,1};

    cout << "\nWant : 3\nWas  : " << s.smallestUniqueSubarray(nums1) << endl;
    cout << "\nWant : 1\nWas  : " << s.smallestUniqueSubarray(nums2) << endl;
    cout << "\nWant : 2\nWas  : " << s.smallestUniqueSubarray(nums3) << endl;


    return 0;
}