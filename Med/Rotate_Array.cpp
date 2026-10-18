#include "iostream"
#include <vector>

using namespace std;

/**
[Medium Problem]

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

*/
template<typename T>
ostream& operator<<(ostream&os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";

    return os;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if(k == 0) return;
        vector<int> copy = nums;
        for(int index = 0; index < size; index++){
            nums[(index + k) % size] = copy[index];
        }
    }
};



int main(){
    Solution s;

    vector<int> nums1 = {1,2,3,4,5,6,7};
    vector<int> nums2 = {-1,-100,3,99};
    vector<int> outp1 = {5,6,7,1,2,3,4};
    vector<int> outp2 = {3,99,-1,-100};
    s.rotate(nums1, 3);
    s.rotate(nums2, 2);
    cout << "Want " << outp1 << ", Was : " << nums1 << endl;
    cout << "Want " << outp2 << ", Was : " << nums2 << endl;


    vector<int> test = {1,2,3,4};
    vector<int> outt ={2,3,4,1};
    s.rotate(test, 3);
    cout << "Want " << outt << ", Was : " << test << endl;

    return -1;
}
