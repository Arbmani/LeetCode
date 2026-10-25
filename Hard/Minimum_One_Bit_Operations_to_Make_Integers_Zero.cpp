#include "iostream"

using namespace std;

/**

Given an integer n, you must transform it into 0 using the following operations any number of times:

-   Change the rightmost (0th) bit in the binary representation of n.

-   Change the ith bit in the binary representation of n if the (i-1)th 
    bit is set to 1 and the (i-2)th through 0th bits are set to 0.

Return the minimum number of operations to transform n into 0.

*/

class Solution {
public:
    int minimumOneBitOperations(int n){
        int operations = 0;
        while (n > 0){
            operations ^= n;
            n >>= 1;
        }
        return operations;
    }

    int minimumOneBitOperations_recursion(int n) {
        if (n == 0) return 0;

        int k = 0;
        while ((1 << k) <= n) k++;
        k--;
        return (1 << (k + 1)) - 1 - minimumOneBitOperations((1 << k) ^ n);      
    }
};


int main(){
    Solution s;

    cout << "Want : 2, Was : " << s.minimumOneBitOperations(3) << endl;
    cout << "Want : 4, Was : " << s.minimumOneBitOperations(6) << endl;


    return 0;
}