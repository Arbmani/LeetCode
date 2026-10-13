#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>

using namespace std;
class Solution{
public:
    /***
     *  [Easy Problem]
     * 
     *  You are given a 0-indexed two-dimensional integer array nums.
     * 
     *  Return the largest prime number that lies on at least one of the diagonals of nums. 
     *  In case, no prime is present on any of the diagonals, return 0.
     * 
     *  Note that:
     * 
     *  -   An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
     * 
     *  -   An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val 
     *      or an i for which nums[i][nums.length - i - 1] = val.
     * 
     *  In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].
     * 
     */
    bool isPrime(int num){
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for(int index = 2; index * index <= num; index++) {
            if (num % index == 0) return false;
        }
        return true; 
    }


    int diagonalPrime(vector<vector<int>> & nums) {
        int max_prime = 0;
        int num_size  = nums.size();
        int val1, val2;
        for (int row = 0; row < nums.size(); row++){
            val1 = nums[row][row];
            val2 = nums[row][nums.size() - row - 1];
            if (isPrime(val1)){
                max_prime = max(max_prime, val1);
            }
            if (isPrime(val2)){
                max_prime = max(max_prime, val2);
            }
        }
        return max_prime;
    }
};


int main() {
    Solution s;
    vector<vector<int>> nums1 = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    vector<vector<int>> nums2 = {{1, 2, 3}, {5,17,7}, {9,11,10}};

    cout << "Want : 11, Was : " << s.diagonalPrime(nums1) << endl;
    cout << "Want : 17, Was : " << s.diagonalPrime(nums2) << endl;


}