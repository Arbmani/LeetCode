#include "string"
#include "iostream" 

#include <ios>
#include <string>


using namespace std;

/**

An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.



*/

class Solution {
private:
    string addStrings(const string& a, const string& b){
        string result;
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry){
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';    
            result.push_back('0' + sum % 10);
            carry = sum / 10;
        }
        for(int l = 0, r = static_cast<int>(result.size()) -1; l < r; ++l, --r){
            char temp = result[l];
            result[l] = result[r];
            result[r] = temp;
        }
        return result;
    }


public:
    bool isAdditiveNumber(string num) {
        int n = static_cast<int>(num.size());
        for (int i = 0; i < n / 2; ++i){
            if (num[0] == '0' && i > 0) break;  
            for (int j = i + 1; j < n - 1; ++j){
                int len1 = i + 1;
                int len2 = j - i;

                if (max(len1, len2) > n - j - 1) break;
                if (num[i + 1] == '0' && j > i + 1)   break;
                string a = num.substr(0, i + 1);
                string b = num.substr(i + 1, j - i);
                int pos  = j + 1;
                while (pos < n){
                    string sum = addStrings(a, b);
                    if(num.compare(pos, sum.size(), sum) != 0) break;
                    pos += static_cast<int>(sum.size());
                    a = b;
                    b = sum;
                }
                if (pos == n) return true;
            }
        }
        return false;
    }
};


int main(){
    Solution s;

    cout << "Want : true, Was : " <<boolalpha << s.isAdditiveNumber("112358") << endl;
    cout << "Want : true, Was : " <<boolalpha << s.isAdditiveNumber("199100199") << endl;

    return 0;
}