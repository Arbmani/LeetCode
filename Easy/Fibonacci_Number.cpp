#include "iostream"
#include "vector"
using namespace std;

/**

The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum 
of the two preceding ones, starting from 0 and 1. That is,

-   F(0) = 0, F(1) = 1

-   F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).


*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> fib(n + 1);
        fib[0] = 0;
        fib[1] = 1;
        for(int index = 2; index <= n; index++) fib[index] = fib[index - 1] + fib[index - 2];
        return fib[n];
    }
};

int main(){
    Solution s;

    cout << "Want 1, Was : " << s.fib(2) << endl;
    cout << "Want 2, Was : " << s.fib(3) << endl;
    cout << "Want 3, Was : " << s.fib(4) << endl;


    return 0;
}