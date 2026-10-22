#include "string"
#include "iostream"

using namespace std;

/**

Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

*/

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for(int index = 0; index < s.size(); index++) 
            if(s[index] != ' ' && (index == 0 || s[index - 1] == ' ')) count++;
        return count;
    }
};


int main(){
    Solution s;

    cout << "Want : 5, Was : " << s.countSegments("Hello, my name is John") << endl;
    cout << "Want : 1, Was : " << s.countSegments("Hello") << endl;

    return 0;
}