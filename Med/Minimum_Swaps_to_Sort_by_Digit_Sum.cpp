#include "vector"
#include "iostream"
#include <ostream>
#include <unordered_map>
#include <vector>
#include "algorithm"
using namespace std;

/**

[Medium Problem]

You are given an array nums of distinct positive integers. 
You need to sort the array in increasing order based on the sum of the 
digits of each number. If two numbers have the same digit sum, 
the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.


*/

class Solution {
private:
    int digitSum(int num){
        int sum = 0;
        while (num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);
            if (sumA != sumB){
                return sumA < sumB;
            }
            return a < b;
        });

        unordered_map<int, int> rank;
        for(int i = 0; i < size; i++){
            rank[sorted[i]] = i;
        }
        vector<int> home(size);
        for(int i = 0; i < size; i++){
            home[i] = rank[nums[i]];
        }
        int swaps = 0;
        for(int i = 0; i < size; i++){
            while(home[i] != i){
                int j = home[i];
                swap(home[i], home[j]);
                swaps++;
            }
        }
        return swaps;      
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {37,100};
    vector<int> nums2 = {22,14,33,7};
    cout << "Want : 1, Was : " << s.minSwaps(nums1) << endl; 
    cout << "Want : 0, Was : " << s.minSwaps(nums2) << endl; 


    return -1;
}