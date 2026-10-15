#include "cmath"
#include "iostream"
using namespace std;


/**
[Medium Problem]

Given an integer n, break it into the sum of k positive integers, 
where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.
*/

class Solution{
public:
    int integerBreak(int n){
        if (n == 2) return 1;
        if (n == 3) return 2;

        int threes    = n / 3;
        int remainder = n % 3;
        if (remainder == 0) return pow(3, threes);
        if (remainder == 1) return pow(3, threes - 1) * 4;
        return pow(3, threes) * 2;
    }
};


int main(){
    Solution s;


    cout << "Want : 1, Was : " << s.integerBreak(2) << endl;
    cout << "Want : 36, Was : " << s.integerBreak(10) << endl;



    return -1;
}