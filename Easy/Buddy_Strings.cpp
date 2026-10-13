#include<iostream>
#include<vector>

using namespace std;

class Solution {
    /**
     * [Easy Problem]
     * 
     *  Given two strings s and goal, return true if you can swap two letters 
     *  in s so the result is equal to goal, otherwise, return false.
     *
     *  Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j 
     *  and swapping the characters at s[i] and s[j].
     *
     *  -   For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
     * 
     */
public:
    bool buddyStrings(string s, string goal){
        if(s.size() != goal.size()) return false;
        int first = -1, second = -1;
        int freq[26] = {};
        for (int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            if (s[i] != goal[i]){
                if (first == -1) first = i;
                else if (second == -1) second = i;
                else return false;
            }
        }
        if (first == -1){
            for(int count : freq)
                if(count > 1) return true;
            return false;
        }
        return second != -1 && 
        s[first] == goal[second] && 
        s[second] == goal[first];

    }
};

int main(){
    Solution solution;

    string in1 = "ab";
    string in2 = "ab";
    string in3 = "aa";
    string op1 = "ba";
    string op2 = "ab";
    string op3 = "aa";

    cout << "Want : true, Was : " <<boolalpha<< solution.buddyStrings(in1, op1) << endl;
    cout << "Want : false, Was : "<<boolalpha << solution.buddyStrings(in2, op2) << endl;
    cout << "Want : true, Was : " <<boolalpha<< solution.buddyStrings(in3, op3) << endl;



    return -1;
}

