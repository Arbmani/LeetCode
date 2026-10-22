#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int index = 1; index < nums.size(); index += 2){
            ans += nums[index-1];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,4,3,2};
    vector<int> nums2 = {6,2,6,5,1,2};

    cout << "Want : 4, Was : " << s.arrayPairSum(nums1) << endl;
    cout << "Want : 9, Was : " << s.arrayPairSum(nums2) << endl;

    return -1;
}