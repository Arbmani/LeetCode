#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
#include <string>

using namespace std;

/**

Given an array of integers cost and an integer target, 
return the maximum integer you can paint under the following rules:

-   The cost of painting a digit (i + 1) is given by cost[i] (0-indexed).

-   The total cost used must be equal to target.

-   The integer does not have 0 digits.

Since the answer may be very large, return it as a string. 
If there is no way to paint any integer given the condition, return "0".


*/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> maxDigits(target + 1, - 1);
        maxDigits[0] = 0;
        for (int digit = 1; digit <= 9; digit++){
            int digitCost = cost[digit - 1];
            for (int remainingCost = digitCost; remainingCost <= target; remainingCost++){
                int prevCost = remainingCost - digitCost;
                if (maxDigits[prevCost] != -1){
                    int digitsIfWeChooseThisDigit = maxDigits[prevCost] + 1;
                    maxDigits[remainingCost] = max(maxDigits[remainingCost], digitsIfWeChooseThisDigit);
                }
            } 
        }
        if (maxDigits[target] == -1) return "0";
        string largestNumber = "";
        int remainingCost = target;
        for (int digit = 9; digit >= 1; digit--){
            int digitCost = cost[digit -1];
            while (remainingCost >= digitCost && maxDigits[remainingCost - digitCost] != -1 && 
                    (maxDigits[remainingCost] == maxDigits[remainingCost - digitCost] + 1)){
                largestNumber += to_string(digit);
                remainingCost -= digitCost;
            }
        }
        return largestNumber;
    }
};

int main(){
    Solution s;

    vector<int> cost1 = {4,3,2,5,6,7,2,5,5};
    vector<int> cost2 = {7,6,5,5,5,6,8,7,8};
    vector<int> cost3 = {2,4,6,2,4,6,4,4,4};

    cout << "\nWant : 7772\nWas  : " << s.largestNumber(cost1, 9) << endl; 
    cout << "\nWant : 85\nWas  : " << s.largestNumber(cost2, 12) << endl; 
    cout << "\nWant : 0\nWas  : " << s.largestNumber(cost3, 5) << endl; 

    return 0;
}