#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
[Easy Problem]

Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counter(52, 0);
        for(char ch : s){
            if ('A' <= ch && ch <= 'Z'){
                counter[26 + (ch - 'A')]++;
            }
            if ('a' <= ch && ch <= 'z'){
                counter[(ch - 'a')]++;
            }
        }
        int ans = 0;
        bool hasOdd = false;
        for(int freq : counter){
            ans += (freq / 2) * 2;
            if(freq % 2 == 1) hasOdd = true;
        }
        if (hasOdd) ans++;

        return ans;
    }
};


int main(){
    Solution s;

    cout << "Want : 1, Was : " << s.longestPalindrome("Aa") << endl;
    cout << "Want : 7, Was : " << s.longestPalindrome("abccccdd")<< endl;
    cout << "Want : 1, Was : " << s.longestPalindrome("a")<< endl;

    return -1;
}