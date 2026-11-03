#include "iostream"

using namespace std;

/**

Given n orders, each order consists of a pickup and a delivery service.

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.


*/

class Solution {
public:
    int countOrders(int n) {
        const long long mod = 1e9 + 7;
        long long       ans = 1;
        for (int i = 1; i <= n; i++) ans = (ans * i * (2 * i - 1)) % mod;
        return (int)ans;        
    }
};

int main(){
    Solution s;

    cout << "Want : 1, Was : " << s.countOrders(1) << endl;
    cout << "Want : 6, Was : " << s.countOrders(2) << endl;

    return 0;
}