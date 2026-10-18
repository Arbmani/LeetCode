#include "iostream"
#include "bitset"
using namespace std;

/**

[Medium Problem]

Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right){
        if(left < right / 2) return 0;
        int counter = 0;

        while(left != right){
            left    >>= 1;
            right   >>= 1;
            ++counter;
        
        }

        return left << counter;
    }


    int rangeBitwiseAnd_slow(int left, int right) {
        if (left < right / 2) return 0;
        bitset<32> bit_left  =  bitset<32>(left);
        bitset<32> bit_right =  bitset<32>(right);
        bitset<32> answer    =  bitset<32>(0); 
        for(int index = 31; index > -1; --index){
            if(bit_left[index] != bit_right[index]) break;
            answer[index] = bit_left[index];
        }
        return static_cast<int>(answer.to_ulong());
    }
};


int main(){
    Solution s;

    cout << "Want : 4, Was : " << s.rangeBitwiseAnd(5, 7) << endl;
    cout << "Want : 0, Was : " << s.rangeBitwiseAnd(0, 0) << endl;
    cout << "Want : 0, Was : " << s.rangeBitwiseAnd(1, 2147483647) << endl;

    return -1;
}