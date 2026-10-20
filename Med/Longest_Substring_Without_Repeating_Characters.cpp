#include "string"
#include "unordered_map"
#include "iostream"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans     = 0;
        int start   = 0;
        unordered_map<char, int> hashMap;
        for (int end = 0; end < s.size(); end++){
            char curr = s[end];
            if(hashMap.count(curr)) start = max(start, 1 + hashMap[curr]);
            hashMap[curr] = end;
            ans           = max(ans, (end - start) + 1);
        }

        return ans;
    }
};

int main(){
    Solution s;

    cout << "Want 3, Was : " << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Want 1, Was : " << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "Want 3, Was : " << s.lengthOfLongestSubstring("pwwkew") << endl;

    return -1;
}