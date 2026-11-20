#include "vector"
#include "iostream"
#include "cstring"


using namespace std;

/*

You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), 
remove them and get k * k points.

Return the maximum points you can get.


*/

class Solution {
private:
    int dp[100][100][100] = {};
    int solve(vector<int>& boxes, int left, int right, int k){
        if (left > right) return 0;
        if (dp[left][right][k] != -1) return dp[left][right][k];
        int ans = (solve(boxes, left, right - 1, 0) + (k + 1) * (k + 1));
        for (int i = left; i < right; i++){
            if (boxes[i] == boxes[right]){
                int candidate = solve(boxes, left, i, k + 1) + solve(boxes, i + 1, right - 1, 0);
                ans = max(ans, candidate);
            }
        }
        return dp[left][right][k] = ans;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if (n == 0) return 0;        
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, n - 1, 0);      
    }
    
};

int main(){
    Solution s = Solution();

    vector<int> boxes1 = {1,3,2,2,2,3,4,3,1};
    vector<int> boxes2 = {1, 1, 1};
    vector<int> boxes3 = {1};

    cout << "\nWant : 23\nWas  : " << s.removeBoxes(boxes1) << endl;
    cout << "\nWant : 9\nWas  : " << s.removeBoxes(boxes2) << endl;
    cout << "\nWant : 1\nWas  : " << s.removeBoxes(boxes3) << endl;
 

    return 0;
}