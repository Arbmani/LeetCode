#include <ostream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


/**

[Hard Problem]

Given an array nums that represents a permutation of integers from 1 to n. 
We are going to construct a binary search tree (BST) by inserting the elements 
of nums in order into an initially empty BST. 

Find the number of different ways to reorder nums so that the constructed BST is 
identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 
1 as a left child, and 3 as a right child. 

The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 10^9 + 7.

*/


template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";

    return os;
}


class Solution {
private:
    long long modularPower(long long base, long long exponent, long long modulo){
        long long result = 1;
        base %= modulo;
        
        while (exponent > 0){
            if(exponent & 1){
                result = result * base % modulo;
            }
            base = base * base % modulo;
            exponent >>= 1;
        }
        return result;
    }
public:
    int numOfWays(vector<int>& nums) {
        const long long modulo = 1000000007LL;
        int nodes = nums.size();

        vector<int> insertionOrder(nodes + 2, - 1);
        for(int index = 0; index < nodes; ++index){
            insertionOrder[nums[index]] = index;
        }
        long long factorialOfNodeCount = 1;

        for(int value = 2; value <= nodes; ++value){
            factorialOfNodeCount = factorialOfNodeCount * value % modulo;
        }
        vector<int> monotonicStack = {0};
        long long productOfSubtreeSizes = 1;

        for(int currentValue = 1; currentValue <= nodes + 1; ++currentValue){
            while(insertionOrder[monotonicStack.back()] > insertionOrder[currentValue]){
                monotonicStack.pop_back();

                int leftBoundary  = monotonicStack.back();
                int rightBoundary = currentValue;
                
                int subTreeSize = rightBoundary - leftBoundary - 1;
                productOfSubtreeSizes = productOfSubtreeSizes * subTreeSize % modulo;
            }
            monotonicStack.push_back(currentValue);
        }
        long long inverseOfSubTreeSizeProduct = modularPower(productOfSubtreeSizes, modulo -2, modulo);
        long long totalValidReorderings = factorialOfNodeCount * inverseOfSubTreeSizeProduct % modulo;
        return (totalValidReorderings - 1 + modulo) % modulo;

    }
};


// 2^(width(next level) + 1) - 1



int main(){
    Solution s;

    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {3,4,5,1,2};
    vector<int> nums3 = {1,2,3};

    cout << "Want : 1, Was : " << s.numOfWays(nums1) << endl;
    cout << "Want : 5, Was : " << s.numOfWays(nums2) << endl;
    cout << "Want : 0, Was : " << s.numOfWays(nums3) << endl;


    return -1;
}