#include "iostream"
#include <climits>

using namespace std;

/**
[Easy Problem]

You have n coins and you want to build a staircase with these coins. 
The staircase consists of k rows where the ith row has exactly i coins. 
The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

*/

class Solution {
public:

    long long cost(long long n){
        return n + (n *(n - 1) / 2);
    }

    int arrangeCoins(int n) {
        long long left  = 0;
        long long right = n;
        // LEFT = 3 RIGHT = 5
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (cost(mid) <= n){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return static_cast<int>(left);
    }
};


int main(){
    Solution s;

    cout << "Want : 2, Was : " << s.arrangeCoins(5) << endl;
    cout << "Want : 3, Was : " << s.arrangeCoins(8) << endl;
    cout << "Want : 3, Was : " << s.arrangeCoins(1804289383) << endl;


    return -1;
}