#include "string"
#include "vector"
#include "iostream"
#include "unordered_map"
#include "queue"
#include "algorithm"
#include <queue>



using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", "; 
    }
    os << "]";

    return os;
}

/**

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. 
Sort the words with the same frequency by their lexicographical order.


*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) freq[word]++;

        auto cmp = [&freq](const string& a, const string& b) {
            if (freq[a] != freq[b]) return freq[a] > freq[b];
            return a < b;
        };

        priority_queue<string, vector<string>, decltype(cmp)> minHeap(cmp);
        for (const auto& [word, count] : freq){
            if (minHeap.size() < k) minHeap.push(word);
            else if (cmp(word, minHeap.top())){
                minHeap.pop();
                minHeap.push(word);
            }
        }
        vector<string> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    Solution s;
    vector<string> words1 = {"i","love","leetcode","i","love","coding"};
    vector<string> words2 = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    
    vector<string> outs1 = {"i","love"};
    vector<string> outs2 = {"the","is","sunny","day"};


    cout << "\nWant : " << outs1 << "\nWas  : " << s.topKFrequent(words1, 2) << endl;
    cout << "\nWant : " << outs2 << "\nWas  : " << s.topKFrequent(words2, 4) << endl;


    return 0;
}