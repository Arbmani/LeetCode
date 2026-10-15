#include<iostream>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s){
        return "§";
    }
};


int main() {
    Solution s;
    cout << "Want : abc, Was : "  << s.removeDuplicateLetters("bcabc") << endl;
    cout << "Want : acdb, Was : " << s.removeDuplicateLetters("cbacdcbc") << endl;

    return -1;
}