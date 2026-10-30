#include "vector" 
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;
template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0 ; i < vec.size(); i++){
        os << vec[i];
        if( i + 1 < vec.size()) os << ", ";
    }
    os << "]";

    return os;
}

/**

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.


*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        int mid = (n  + 1) / 2;
        int j = mid - 1;
        int k = n - 1;

        for(int index = 0; index < n; index++){
            if (index % 2 == 0) nums[index] = sorted[j--];
            else                nums[index] = sorted[k--]; 
        }
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {1,5,1,1,6,4};
    vector<int> nums2 = {1,3,2,2,3,1};
    s.wiggleSort(nums1);
    s.wiggleSort(nums2);

    vector<int> want1 = {1,6,1,5,1,4};
    vector<int> want2 = {2,3,1,3,1,2};

    cout << "Want : " << want1 << ", Was : " << nums1 << endl;
    cout << "Want : " << want2 << ", Was : " << nums2 << endl;


    return 0;
}