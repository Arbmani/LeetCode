#include "string"
#include "vector"
#include "iostream"

using namespace std;

/**

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

*/

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        int maxFreq = 0;
        for (char c : s) maxFreq = max(maxFreq, ++freq[(unsigned char) c]);
        vector<string> buckets(maxFreq + 1);
        for (int i = 0; i < 256; i++){
            if (freq[i] > 0) buckets[freq[i]].append(freq[i], (char)i);
        }
        string ans;
        for (int i = maxFreq; i >= 1; i --) ans += buckets[i];
        return ans;
    }
};

vector<string> split(string str, char cha){
    vector<string> ans;
    string word = "";
    for (char c : str){
        if (c == cha){
            if (!word.empty()){
                ans.push_back(word);
                word.clear();
            }
        }
        else word += c;
    }
    if (!word.empty()) ans.push_back(word);
    return ans;
}


int main(){
    Solution s;
    cout << "\nWant : eert\nWas  : " << s.frequencySort("tree") << endl;
    cout << "\nWant : aaaccc\nWas  : " << s.frequencySort("cccaaa") << endl;
    cout << "\nWant : bbAa\nWas  : " << s.frequencySort("Aabb") << endl;


    return 0;
}