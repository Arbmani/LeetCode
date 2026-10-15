#include <string>
#include <iostream>

using namespace std;
/*

You are given two positive integers num and sum.

A positive integer n is good if it satisfies both of the following:

-   The number of digits in n is exactly num.

-   The sum of digits in n is exactly sum.

The score of a good integer n is the sum of the squares of digits in n.

Return a string denoting the good integer n that achieves the maximum score. 
If there are multiple possible integers, return the maximum ​​​​​​​one. If no such integer exists, return an empty string.




*/

//#include <vector>
#include <cmath>
class Solution {
public:
    string maxSumOfSquares(int num, int sum){
        string ans = "";
        if (sum < 1 || sum > 9 * num) return ans;
        ans.reserve(num);
        for(int i = 0; i < num; i++){
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};

// n = 3 sum = 3
// 111, 102, 120, 300, 210, 201, 

int main() {
    Solution s;

    cout << "Want 30, Was : " << s.maxSumOfSquares(2, 3) << endl;
    cout << "Want 98, Was : " << s.maxSumOfSquares(2, 17) << endl;
    cout << "Want \"\", Was : " << s.maxSumOfSquares(1, 10) << endl;
    cout << "Want 81, Was : " << s.maxSumOfSquares(1, 9) << endl;


    return -1;
}