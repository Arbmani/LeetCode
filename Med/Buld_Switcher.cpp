#include "iostream"
#include "cmath"

using namespace std;

/**

There are n bulbs that are initially off.
You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb 
(turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

*/

// 0: 0000 0000
// 1: 1111 1111
// 2: 1010 1010
// 3: 1000 1110

class Solution {
public:
    int bulbSwitch(int n) {
        return static_cast<int>(sqrt(n));   
    }
};


int main(){
    Solution s;

    cout << "Want : 1, Was : " << s.bulbSwitch(3) << endl;
    cout << "Want : 0, Was : " << s.bulbSwitch(0) << endl;
    cout << "Want : 1, Was : " << s.bulbSwitch(1) << endl;

    return 0;
}