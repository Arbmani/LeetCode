#include <string>
#include <vector>
#include <iostream>
#include "unordered_set"
#include <cmath>
#include "bitset"
using namespace std;


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> seen;
        for(const string& num : nums){
            seen.insert(stoi(num, nullptr, 2));
        }
        int value = pow(2,nums[0].size()) - 1;
        for(int index = 0; index <= value; index++){
            if (seen.find(index) == seen.end()){
                return bitset<32>(index).to_string().substr(32 - nums[0].size());
            }
        }

        return "TODO";        
    }
};


int main(){
    Solution s;
    vector<string> nums1 = {"01","10"};
    vector<string> nums2 = {"00","01"};
    vector<string> nums3 = {"111","011","001"};

    cout << "Want :  11, Was : " << s.findDifferentBinaryString(nums1) << endl;
    cout << "Want :  11, Was : " << s.findDifferentBinaryString(nums2) << endl;
    cout << "Want : 101, Was : " << s.findDifferentBinaryString(nums3) << endl;

    return -1;
}