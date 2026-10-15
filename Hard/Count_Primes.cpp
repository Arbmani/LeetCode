#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    bool isPrime(int num){
        if (num < 2)                        return false;
        if (num == 2     || num == 3)       return true;
        if (num % 2 == 0 || num % 3 == 0)   return false;
        for (int index = 5; index <= num / index; index += 6){
            if(num % (index) == 0 || num % (index + 2) == 0) return false;
        }
        return true;
    }

    int countPrimes_slow(int n){
        if (n <= 2) return 0;
        if (n <= 3) return 1;
        if (n <= 5) return 2;
        int counter = 2;
        for(int index = 5; index < n; index += 6){
            if (index     < n && isPrime(index))     counter++;
            if (index + 2 < n && isPrime(index + 2)) counter++;
        }
        return counter;
    }
    int countPrimes(int n){
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int index = 2; index <= (n - 1) / index; index++){
            if (isPrime[index]) {
                for(int multiple = index * index; multiple < n; multiple += index){
                    isPrime[multiple] = false;
                }
            }
        }
        int counter = 0;
        for(int index = 2; index < n; index++){
            if(isPrime[index]) counter++;
        }
        return counter;
    }
    
};


int main() {
    Solution s;
    cout << "Want : 4, Was : " << s.countPrimes(10) << endl;
    cout << "Want : 0, Was : " << s.countPrimes(0) << endl;
    cout << "Want : 0, Was : " << s.countPrimes(1) << endl;
    cout << "Want : 3, Was : " << s.countPrimes(7) << endl;


    return  -1;
}




