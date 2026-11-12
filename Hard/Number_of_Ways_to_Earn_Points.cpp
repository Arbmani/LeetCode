#include "vector"
#include "iostream"

using namespace std;

/**

There is a test that has n types of questions. 
You are given an integer target and a 0-indexed 2D integer 
array types where types[i] = [counti, marksi] indicates that 
there are counti questions of the ith type, 
and each one of them is worth marksi points.

Return the number of ways you can earn exactly target points in the exam. 
Since the answer may be too large, return it modulo 109 + 7.

Note that questions of the same type are indistinguishable.

-   For example, if there are 3 questions of the same type, 
    then solving the 1st and 2nd questions is the same as 
    solving the 1st and 3rd questions, or the 2nd and 3rd questions.

*/

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (auto& type : types){
            vector<int> newDP(target + 1, 0);
            int count = type[0];
            int marks = type[1];
            for (int remainder = 0; remainder < marks && remainder <= target; remainder++){
                long long windowSum = 0;
                for (int score = remainder; score <= target; score += marks){
                    windowSum = (windowSum + dp[score]) % mod;
                    int removeScore = score - (count + 1) * marks;
                    if (removeScore >= 0) windowSum = (windowSum - dp[removeScore] + mod) % mod;
                    newDP[score] = windowSum;
                }
            }
            dp = std::move(newDP);
        }
        return dp[target];
    }
};

int main(){
    Solution s;

    vector<vector<int>> types1 = {{6,1 }, {3, 2}, {2, 3}};
    vector<vector<int>> types2 = {{50 ,1}, {50, 2}, {50, 5}};
    vector<vector<int>> types3 = {{6, 1}, {3, 2}, {2, 3}};


    cout << "\nWant : 7\nWas  : " << s.waysToReachTarget(6, types1) << endl;
    cout << "\nWant : 4\nWas  : " << s.waysToReachTarget(5, types2) << endl;
    cout << "\nWant : 1\nWas  : " << s.waysToReachTarget(18, types3) << endl;

    return 0;
}