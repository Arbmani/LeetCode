#include "iostream"
#include <ios>


using namespace std;
/**
A perfect number is a positive integer that is equal to the sum of its positive divisors, 
excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

*/

class Solution {
private:
    void printerPooper(){
        cout << "printerPooper" << endl;
    }

public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int divisor = 2; divisor <= num / divisor; divisor++){
            if(num % divisor == 0){
                sum += divisor;
                int pairedDivisor = num / divisor;
                if (pairedDivisor != divisor) sum += pairedDivisor;
            }
            if (sum > num) return false;
        }
        return sum == num;
    }
};

void poop(){
    cout << "poop of poops" << endl;
}

int main(){
    Solution s;

    cout << "Want :  true, Was : " << boolalpha << s.checkPerfectNumber(28) << endl;
    cout << "Want : false, Was : " << boolalpha << s.checkPerfectNumber(7) << endl;

    poop();

    return -1;
}