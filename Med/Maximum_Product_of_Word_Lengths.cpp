#include "string"
#include "vector"
#include "iostream"

using namespace std;

/*

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. If no such two words exist, return 0.

*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        for(int i = 0; i < n; i++) for (char cha : words[i]) mask[i] |= (1 << (cha - 'a'));
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if ((mask[i] & mask[j]) == 0){
                    int temp = words[i].size() * words[j].size();
                    ans = max(ans, temp);
                }
            }
        }
        return ans;        
    }
};

int main(){
    Solution s;

    vector<string> words1 = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> words2 = {"a","ab","abc","d","cd","bcd","abcd"};
    vector<string> words3 = {"a","aa","aaa","aaaa"};

    cout << "Want : 16, Was : " << s.maxProduct(words1) << endl;
    cout << "Want :  4, Was : " << s.maxProduct(words2) << endl;
    cout << "Want :  0, Was : " << s.maxProduct(words3) << endl;

    return 0;
}