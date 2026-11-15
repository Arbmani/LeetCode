#include "vector"
#include "iostream"

#include "unordered_map"

using namespace std;

/**

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
return the number of tuples (i, j, k, l) such that:

-   0 <= i, j, k, l < n

-   nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

    ->   (nums1[i] + nums2[j]) == - (nums3[k] + nums4[l])

*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> left;
        for (int num1 : nums1) for (int num2 : nums2) left[num1 + num2]++;
        int ans = 0;
        for (int num3 : nums3){
            for (int num4 : nums4){
                auto it = left.find(-(num3 + num4));
                if (it != left.end()) ans += it->second;
            }
        }
        return ans;
    }


    int fourSumCount_almostperfect(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;

        for (int num1 : nums1) for (int num2 : nums2)   left[num1 + num2]++;
        for (int num3 : nums3) for (int num4 : nums4)   right[num3 + num4]++; 
        int ans = 0;
        for (auto [key, freq] : left){
            if (right.count(-key)){
                ans += freq * right[-key];
            }
        }
        
        
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1_1 = {1, 2};
    vector<int> nums2_1 = {-2, -1};
    vector<int> nums3_1 = {-1, 2};
    vector<int> nums4_1 = {0, 2};


    vector<int> nums1_2 = {0};
    vector<int> nums2_2 = {0};
    vector<int> nums3_2 = {0};
    vector<int> nums4_2 = {0};

    cout << "\nWant : 2\nWas  : " << s.fourSumCount(nums1_1, nums2_1, nums3_1, nums4_1) << endl;
    cout << "\nWant : 1\nWas  : " << s.fourSumCount(nums1_2, nums2_2, nums3_2, nums4_2) << endl;


    return 0;
}