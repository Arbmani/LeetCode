#include "string"
#include "iostream"
#include "algorithm"
//Maybe convert string to list

using namespace std;

class Solution {
public:
    //bool isSorted(string s){
//
    //    return true;
    //}

    int minOperations(string s) {
        int n = s.length();
        char minChar = s[0], maxChar = s[0];
        bool isSorted = 1;

        for(int index = 1; index < n; index++){
            if(s[index] < s[index -1]) isSorted = 0;
            minChar = min(minChar, s[index]);
            maxChar = max(maxChar, s[index]);
        }
        if (isSorted) return 0;
        if (n == 2)   return -1;
        if (s.front() == minChar || s.back() == maxChar) return 1;
        for (int index = 1; index < n - 1; index++){
            if(s[index] == minChar || s[index] == maxChar) return 2;
        }
        return 3;
    }
};

int main(){
    Solution s;


    cout << "Want :  1, Was : " << s.minOperations("dog") << endl;
    cout << "Want :  2, Was : " << s.minOperations("card") << endl;
    cout << "Want : -1, Was : " << s.minOperations("gf") << endl;

    return -1;;
}