#include "iostream"

using namespace std;

/**

You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. 
Apply the following algorithm on arr:

-   Starting from left to right, remove the first number and 
    every other number afterward until you reach the end of the list.

-   Repeat the previous step again, but this time from right to left, 
    remove the rightmost number and every other number from the remaining numbers.

-   Keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Given the integer n, return the last number that remains in arr.



*/

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool leftToRight = true;

        while (remaining > 1) {
            if(leftToRight || remaining % 2 == 1) head += step;
            remaining   /= 2;
            step        *= 2;
            leftToRight  = !leftToRight;

        }
        return head;
    }
};

int main(){
    Solution s;

    cout << "Want : 6, Was : " << s.lastRemaining(9) << endl;
    cout << "Want : 1, Was : " << s.lastRemaining(1) << endl;


    return 0;
}