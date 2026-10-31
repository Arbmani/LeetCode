#include "iostream"
#include <string>

using namespace std;

/**

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

*/

class Solution {
public:
    int findNthDigit(int n) {
        long long digitLen = 1, start = 1, count = 9;
        while(n > count * digitLen){
            n -= count * digitLen;
            digitLen++;
            count *= 10;
            start *= 10;
        }
        long long number = start + (n - 1) / digitLen;
        int index = (n - 1) % digitLen;
        string str = to_string(number);

        return str[index] - '0';
    }
};

int main(){
    Solution s;

    cout << "Want : 3, Was : " << s.findNthDigit(3) << endl;
    cout << "Want : 0, Was : " << s.findNthDigit(11) << endl;

    return 0;
}