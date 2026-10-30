#include "vector"
#include "iostream"
#include <climits>

using namespace std;

/**

Your task is to calculate a^b mod 1337 
where a is a positive integer and b is an extremely large positive integer given in the form of an array.

*/
class Solution {
private:
    static constexpr int mod = 1337;
    int modPow(int a, int exp){
        int result = 1;
        a %= mod;
        while (exp > 0){
            if (exp % 2 == 1) result = (result * a) % mod;
            a = (a * a) % mod;
            exp /= 2;
        }
        return result;
    }


public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int digit : b) ans = (modPow(ans, 10) * modPow(a, digit)) % mod;
        return ans;        
    }
};

int main(){
    Solution s;

    vector<int> b1 = {3, 3, 3, 1};
    vector<int> b2 = {1, 0};
    vector<int> b3 = {4,3,3,8,5,2};

    cout << "Want :    8, Was : " << s.superPow(2, b1) << endl;
    cout << "Want : 1024, Was : " << s.superPow(2, b2) << endl;
    cout << "Want :    1, Was : " << s.superPow(1, b3) << endl;

    return -1;
}