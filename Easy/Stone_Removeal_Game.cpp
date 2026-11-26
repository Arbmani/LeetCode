#include "iostream"

using namespace std;

/*

Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.

-   Alice starts by removing exactly 10 stones on her first turn.

-   For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.

The player who cannot make a move loses the game.

Given a positive integer n, return true if Alice wins the game and false otherwise.



*/

// Alice vinner om: n <= 10,
// Alice vinner om: 19 <= n < = 27,
// Alice vinner om: 34 <= n <= 40,
// Alice vinner om: 45  <= n <= 50,

class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int  fac = 10;
        while (n >= fac){
            ans = !ans;
            n  -= fac;
            fac--;
        }

        return ans;
    }
};

int main(){
    Solution s;

    cout << "\nWant : true\nWas  : " << boolalpha << s.canAliceWin(12) << endl;
    cout << "\nWant : false\nWas  : " << boolalpha << s.canAliceWin(1) << endl;


    return 0;
}