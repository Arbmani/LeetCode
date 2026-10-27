#include "iostream"
#include "vector"
#include <vector>

using namespace std;

/**

You are given an integer array target. 
You have an integer array initial of the same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.

*/
//if (target[index] > target[index - 1]) ans += (target[index] - target[index - 1]);
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int index = 1; index < target.size(); index++) ans += max(0, target[index] - target[index - 1]);
        return ans;        
    }
};


int main(){
    vector<int> target1 = {1,2,3,2,1};
    vector<int> target2 = {3,1,1,2};
    vector<int> target3 = {3,1,5,4,2};
    Solution s;
    cout << "Want : 3, Was : " << s.minNumberOperations(target1) << endl;
    cout << "Want : 4, Was : " << s.minNumberOperations(target2) << endl;
    cout << "Want : 7, Was : " << s.minNumberOperations(target3) << endl;

    return 0;
}