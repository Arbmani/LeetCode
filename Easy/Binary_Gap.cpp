#include "iostream"


using namespace std;

/**

Given a positive integer n, find and return the longest distance between any two adjacent 1's 
in the binary representation of n. If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's). 
The distance between two 1's is the absolute difference between their bit positions. 

For example, the two 1's in "1001" have a distance of 3.

*/

class Solution {
public:
    int binaryGap(int n) {
        int rest;
        int prev_index = -1;
        int index      =  0;
        int ans        = 0;
        while(n > 0){
            rest = n % 2;
            n   /= 2;

            if(rest == 1){
                if(prev_index != -1) ans = max(ans, index - prev_index);
                prev_index = index;
            }

            index++;
        }

        return ans;     
    }
};



int main(){
    Solution s;

    cout << "Want : 2, Was : " << s.binaryGap(22) << endl;
    cout << "Want : 0, Was : " << s.binaryGap(8) << endl;
    cout << "Want : 2, Was : " << s.binaryGap(5) << endl;

    return -1;
}