#include "iostream"


using namespace std;

/**

Given two integers a and b, return the sum of the two integers without using the operators + and -.

*/

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;        
    }
};


int main(){
    Solution s;

    cout << "Want : 3, Was : " << s.getSum(1, 2) <<  endl;
    cout << "Want : 5, Was : " << s.getSum(2, 3) <<  endl;

    return 0;
}