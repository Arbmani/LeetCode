#include "string"
#include "vector"
#include "iostream"
#include <vector>

using namespace std;

/**
[Medium Problem]

Given a string s and an array of strings words, 
return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from 
the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>&words){
        vector<vector<pair<int, int>>> waiting(26);
        int ans = 0;

        for(int index = 0; index < words.size(); ++index){
            if (words[index].empty()) {
                ++ans;
            } else {
                waiting[words[index][0] - 'a'].push_back({index, 0});
            }
        }

        for (char c: s){
            vector<pair<int, int>> current;
            current.swap(waiting[c - 'a']);
            
            for(auto [wordIndex, pos] : current){
                ++pos;
                if (pos == words[wordIndex].size()) ++ans;
                else{
                    char nextChar = words[wordIndex][pos];
                    waiting[nextChar - 'a'].push_back({wordIndex, pos});
                }
            }
        }
        return ans;
    }


    int numMatchingSubseq_verySlow(string s, vector<string>&words){
        int stri_size = s.size(), ans = 0; 
        for(string word: words){
            int word_size = word.size();
            if (word_size >  stri_size) continue;
            if (word_size == stri_size){
                ans += (word == s ? 1 : 0);
                continue;
            }
            int i = 0, j = 0;
            while(i < word_size && j < stri_size){
                if (word[i] == s[j]) i++;
                j++; 
            }
            if (i == word_size) ans += 1;
        }
        return ans;
    }
};


int main(){

    vector<string> words1 = {"a","bb","acd","ace"};
    vector<string> words2 = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    Solution s;
    cout << "Want : 3, Was : " << s.numMatchingSubseq("abcde", words1) << endl;
    cout << "Want : 2, Was : " << s.numMatchingSubseq("dsahjpjauf", words2) << endl;


    return -1;
}