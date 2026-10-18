#include "iostream"
using namespace std;


/**
[Medium Problem]

Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.


*/

class Solution {
public:
    int integerReplacement(int n){
        long long num = n;
        int ans       = 0;

        while(num != 1){
            if(num % 2 == 0){
                num /= 2;
            } else if(num == 3 || num % 4 == 1){
                num--;
            } else {
                num++;
            }
            ans++;
        }
        return ans;
    }



    //int dfs(long long n, int ans){
    //    if (n == 1)      return ans;
    //    if (n  % 2 == 0) return dfs(n / 2, ans + 1);
    //    return min(dfs(n + 1, 1 + ans), dfs(n - 1, 1 + ans));
    //}
//
    //int integerReplacement(int n) {
    //    return dfs(n, 0);      
    //}
};



int main(){
    Solution s;

    cout << "Want : 3, Was : " << s.integerReplacement(8) << endl;
    cout << "Want : 4, Was : " << s.integerReplacement(7) << endl;
    cout << "Want : 2, Was : " << s.integerReplacement(4) << endl;

    return -1;
}