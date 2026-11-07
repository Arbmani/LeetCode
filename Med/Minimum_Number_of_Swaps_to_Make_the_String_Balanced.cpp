#include "string"
#include "iostream"

using namespace std;

/**

You are given a 0-indexed string s of even length n. 
The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

-   It is the empty string, or

-   It can be written as AB, where both A and B are balanced strings, or

-   It can be written as [C], where C is a balanced string.

You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.


*/

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, maxImbalance = 0;

        for (char c : s){
            if (c == '[')   balance ++;
            else            balance--;
            maxImbalance = max(maxImbalance, -balance);
        }
        return (maxImbalance + 1) / 2;
    }
};

int main(){
    Solution s;

    cout << "\nWant : 1\nWas  : " << s.minSwaps("][][") << endl;
    cout << "\nWant : 2\nWas  : " << s.minSwaps("]]][[[") << endl;
    cout << "\nWant : 0\nWas  : " << s.minSwaps("[]") << endl;

    return 0;
}