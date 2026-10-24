#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>



using namespace std;

/*

Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

*/

template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    
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
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int num : nums){
            counter[num]++;
            if (counter.size() <= 2) continue;
            unordered_map<int, int> newCounter;
            for(auto& [num, cunt] : counter){
                if (cunt > 1) newCounter[num] = cunt - 1;
            }
            counter = newCounter;
        }
        vector<int> res;
        for (auto& [num, cunt] : counter){
            if (count(nums.begin(), nums.end(), num) > (int)(nums.size() / 3)) res.push_back(num);
        }
        return res;
    
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {3,2,3};
    vector<int> nums2 = {1};
    vector<int> nums3 = {1,2};

    vector<int> out1 = {3};
    vector<int> out2 = {1};
    vector<int> out3 = {1,2};

    cout << "Want : " << out1 << "   , Was : " << s.majorityElement(nums1) << endl;
    cout << "Want : " << out2 << "   , Was : " << s.majorityElement(nums2) << endl;
    cout << "Want : " << out3 << ", Was : " << s.majorityElement(nums3) << endl;


    return 0;
}