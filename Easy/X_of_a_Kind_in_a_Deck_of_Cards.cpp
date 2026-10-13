#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>

using namespace std;

class Solution {
    /**
     * [Easy Problem]
     * 
     *  You are given an integer array "deck" where "deck[i]" represents the nubmer written on the ith card
     *  Position the cards into one or more groups such that
     *  
     *  -   Each group has excatly "x" cards where x > 1, and
     *  -   All the cards in one group have the same integer written on them
     * 
     *  Return "true" if such partition is possible, or false otherwise
     * 
     */


public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card: deck){
            freq[card]++;
        }
        int g = 0;
        for(auto& entry :freq){
            g = gcd(g, entry.second);
        }
        return g >=2;
    }

};


int main(){
    Solution solution;
    vector<int> deck1 = {1,2,3,4,4,3,2,1};
    vector<int> deck2 = {1,1,1,2,2,2,3,3};

    cout << "Want: True, Was: " << boolalpha << solution.hasGroupsSizeX(deck1) << endl;
    cout << "Want: False, Was: " << boolalpha << solution.hasGroupsSizeX(deck2) << endl;

    return 0; 
}