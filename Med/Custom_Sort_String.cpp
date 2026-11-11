#include "string"
#include "iostream"

using namespace std;

/**

You are given two strings order and s. 
All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. 
More specifically, if a character x occurs before a character y in order, 
then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.


*/

class Solution {
public:
    string customSortString(string order, string s) {
        return "";
    }
};

int main(){
    Solution s;

    cout << "\nWant : cbad\nWas  : " << s.customSortString("cba", "abcd") << endl;
    cout << "\nWant : bcad\nWas  : " << s.customSortString("bcafg", "abcd") << endl;

    return 0;
}