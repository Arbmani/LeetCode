#include "string"
#include "iostream"
#include <string>
using namespace std;

/**
[Medium Problem]

Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.


*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        string ans = "";
        for (char c : num){
            while(!ans.empty() && k > 0 && ans.back() > c){
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while(k > 0){
            ans.pop_back();
            k--;
        }
        int i = 0;
        while(i < ans.size() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};


int main(){
    Solution s;

    cout << "Want : \"1219\", Was : " << s.removeKdigits("1432219", 3) << endl;
    cout << "Want : \" 200\", Was : " << s.removeKdigits("10200", 1) << endl;
    cout << "Want : \"   0\", Was : " << s.removeKdigits("10", 2) << endl;



    return -1;
}