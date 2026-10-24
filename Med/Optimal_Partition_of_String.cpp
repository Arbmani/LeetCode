#include "string"
#include "iostream"
#include "unordered_set"
using namespace std;

/**

Given a string s, partition the string into one or more substrings 
such that the characters in each substring are unique. 
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

*/

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int ans = 1;

        for (char curr : s){
            if (set.count(curr)){
                ans++;
                set.clear();
            }
            set.insert(curr);
        }
        return ans;
    }
};




int main(){
    Solution s;

    cout << "Want : 4, Was : " << s.partitionString("abacaba") << endl;
    cout << "Want : 6, Was : " << s.partitionString("ssssss") << endl;

    return 0;
}