#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int sumCounts(vector<int>& nums){
        return -1;
    }
};


int main(){
    Solution s;

    vector<int> nums1 = {1,2,1};
    vector<int> nums2 = {1,1};
    cout << "Want : 15, Was : " << s.sumCounts(nums1) << endl;
    cout << "Want : 3, Was : " << s.sumCounts(nums2) << endl;


}


