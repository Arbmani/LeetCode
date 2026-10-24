#include "string" 
#include "iostream"
#include "vector"

using namespace std;

/**

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.



*/

class Solution {
public:
    string removeStars(string s) {
        vector<char> str;
        for(char cha : s){
            if (cha == '*'){
                if (!str.empty()) str.pop_back();
            }
            else str.push_back(cha);
        }        
        return string(str.begin(), str.end());
    }
};


int main(){
    Solution s;

    cout << "Want : \"lecoe\", Was : " << s.removeStars("leet**cod*e") << endl;
    cout << "Want : \"\",      Was : " << s.removeStars("erase*****") << endl;


    return 0;
}