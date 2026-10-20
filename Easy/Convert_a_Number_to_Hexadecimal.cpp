#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/**
[Easy Problem]

Given a 32-bit integer num, return a string representing its hexadecimal representation. 
For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, 
and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.


*/


class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string digits = "0123456789abcdef";
        string ans;

        for(int index = 0; index < 8 && num != 0; index++){
            int digit = num & 0xf;
            ans.push_back(digits[digit]);
            num = static_cast<unsigned int>(num) >> 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;

    cout << "Want : 1a, Was : " << s.toHex(26) << endl;
    cout << "Want : 1, Was : " << s.toHex(1) << endl;
    cout << "Want : ffffffff, Was : " << s.toHex(-1) << endl;
    cout << "Want : 0, Was : " << s.toHex(0) << endl;
    cout << "Want : fffffffe, Was : " << s.toHex(-2) << endl;
    return -1;
}