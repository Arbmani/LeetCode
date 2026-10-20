#include "string" 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <ostream>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";
    
    return os;
}

/**
[Hard Problem]

Given an array of strings "words" (without duplicates), return all the 
concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised 
entierly of at least two shorter words (not necessarily distinct) in the given array.
*/

#include "unordered_set"
#include "unordered_map"

class Solution {
public:
    bool dfs(string word, unordered_map<string, bool>& hashMap, unordered_set<string>& wordSet){
        if(hashMap.count(word)) return hashMap[word];
        for(int index = 1; index < word.size(); index++){
            string prefix = word.substr(0, index);
            string suffix = word.substr(index);
            if((wordSet.count(prefix) && wordSet.count(suffix)) ||
                (wordSet.count(prefix) && dfs(suffix, hashMap, wordSet))) return hashMap[word] = true;
        }
        return hashMap[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> wordSet = unordered_set<string>(words.begin(), words.end());
        unordered_map<string, bool> hashMap;

        for(const string& word: words){
            wordSet.erase(word);
            if(dfs(word, hashMap, wordSet)) ans.push_back(word);
            wordSet.insert(word);
        }

        return ans;
    }
};


