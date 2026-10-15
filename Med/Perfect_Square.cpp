#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



*/


// Find the largest GCD 


// Hitta alla primes som är correcta under sqrt(num)
// 


class Solution {
public:
    bool isPrimes(int n){
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for(int index = 5; index <= n / index; index += 6){
            if (n % index == 0 || n % (index + 2) == 0) return false;
        }
        return true;
    }
    int numSquares(int n) {
        vector<int> squares = {};
        for (int index = 1; index <= n / index; index++){
            squares.push_back(index * index);
        }  
        unordered_map<int, int> map;
        map[0] = 0;
        auto dfs = [&](auto&& self, int num) -> int{
            if (map.find(num) != map.end()) return map[num];
            int temp = INT_MAX;
            for(int index = squares.size() -1; index >= 0; index--){
                if (squares[index] <= num){
                    temp = min(temp, 1 + self(self, num - squares[index]));
                } 
            }
            map[num] = temp;
            return temp;};
        return dfs(dfs, n);
    }
};

int main() {
    Solution s;

    cout << "Want : 3, Was : " << s.numSquares(12) << endl;
    cout << "Want : 2, Was : " << s.numSquares(13) << endl;


    return -12;
}
