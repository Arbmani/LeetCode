#include "algorithm"
#include "iostream"
#include <string>

using namespace std;

/**

Given an integer num, return a string of its base 7 representation.

*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans          = "";
        bool negative       = num < 0;
        num = abs(num);
        while (num){
            int rest = num % 7;
            ans += to_string(rest);
            num /= 7;
        }
        if (negative) ans+= "-";
        reverse(ans.begin(), ans.end());
        return ans;      
    }
};


int main(){
    Solution s;

    cout << "Want : 202, Was : " << s.convertToBase7(100) << endl;
    cout << "Want : -10, Was :  " << s.convertToBase7(-7) << endl;


    return 0;
}