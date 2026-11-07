#include "vector"
#include "stack"
#include "iostream"

using namespace std;

/**

You are given an integer array nums and an integer threshold.

Find any subarray of nums of length k such that every element in the subarray is greater than threshold / k.

Return the size of any such subarray. If there is no such subarray, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.


*/

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";

    return os;
} 

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> stac;

        for (int i = 0; i < n; i++){        // previous strictly smaller
            while (!stac.empty() && nums[stac.top()] >= nums[i]) stac.pop();
            left[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }
        
        while (!stac.empty()) stac.pop();

        for (int i = n - 1; i >= 0; i--){   // next strictly larger
            while (!stac.empty() && nums[stac.top()] >= nums[i]) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        for (int i = 0; i < n; i++){
            int k = right[i] - left[i] - 1; // (strictly larger than i - strictly smaller than i) - 1
            if (1LL * nums[i] * k > threshold) return k;
        }
        return -1;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,3,4,3,1};
    vector<int> nums2 = {6,5,6,5,8};

    cout << "\nWant : 3\nWas  : " << s.validSubarraySize(nums1, 6) << endl;
    cout << "\nWant : 5\nWas  : " << s.validSubarraySize(nums2, 7) << endl;

    return 0;
}