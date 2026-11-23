#include "string"
#include "iostream"


using namespace std;

/*

Given a string s consisting of only the characters 'a' and 'b', 
return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

*/

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};

int main(){
    Solution s;

    cout << "\nWant  : true\nWas  : " << boolalpha << s.checkString("aaabbb") << endl;
    cout << "\nWant  : false\nWas  : " << boolalpha << s.checkString("abab") << endl;
    cout << "\nWant  : true\nWas  : " << boolalpha << s.checkString("bbb") << endl;



    return 0;
}