#include "vector"
#include "iostream"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if(i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

/**

Given an integer array nums and a positive integer k, 
return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained 
by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a 
subsequence b (of the same length) if in the first position 
where a and b differ, subsequence a has a number less than the 
corresponding number in b. For example, [1,3,4] is more competitive 
than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.


*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k){
        vector<int> ans;
        ans.reserve(k);
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while(!ans.empty() && 
                    ans.back() > nums[i] &&
                    ans.size() + (n - i) > k) ans.pop_back();
            if (ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }


    vector<int> mostCompetitive_slow(vector<int>& nums, int k) {
        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < nums.size(); i++){
            while(!ans.empty() && ans.back() > nums[i] && (nums.size() - i) + ans.size() > k){
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        while(ans.size() > k) ans.pop_back();

        return ans;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {3, 5, 2, 6};
    vector<int> nums2 = {2,4,3,3,5,4,9,6};

    vector<int> out1  = {2,6}; 
    vector<int> out2  = {2,3,3,4}; 

    cout << "\nWant : " << out1 << "\nWas  : " << s.mostCompetitive(nums1, 2) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.mostCompetitive(nums2, 4) << endl;


    return 0;
}