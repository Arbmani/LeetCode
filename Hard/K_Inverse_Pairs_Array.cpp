#include <iostream>
#include "cmath"
#include "vector"

using namespace std;

/**

For an integer array nums, an inverse pair is a pair of integers [i, j] 
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n
such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

*/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int modulo = pow(10,9) + 7;
        vector<int> prev(k + 1, 0);
        prev[0] = 1;

        for(int n_index = 1; n_index <= n; n_index++){
            vector<int> curr(k + 1, 0);
            int total = 0;
            for(int k_index = 0; k_index <= k; k_index++){
                if (k_index >= n_index) total = (total - prev[k_index - n_index] + modulo) % modulo;
                total = (total + prev[k_index]) % modulo;
                curr[k_index] = total;
            }
            prev = curr;
        }

        return prev[k];          
    }
};



int main(){
    Solution s;

    cout << "Want : 1, Was : " << s.kInversePairs(3, 0) << endl;
    cout << "Want : 2, Was : " << s.kInversePairs(3, 1) << endl;
    cout << "Want : 2, Was : " << s.kInversePairs(1000, 1000) << endl;

    return -1;
}