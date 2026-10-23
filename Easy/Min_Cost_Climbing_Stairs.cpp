#include "vector"
#include "iostream"

using namespace std;

/**

You are given an integer array cost where cost[i] is the cost of ith step on a staircase.

Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the staircase, which is the position just past the last step (index cost.length).



*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0, prev2 = 0;

        for(int index = 2; index <= cost.size(); index++){
            int curr = min(prev1 + cost[index - 1], prev2 + cost[index - 2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};


int main(){
    Solution s;
    vector<int> cost1 = {10,15,20};
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Want : 15, Was : " << s.minCostClimbingStairs(cost1) << endl;
    cout << "Want :  6, Was : " << s.minCostClimbingStairs(cost2) << endl;

    return 0;
}