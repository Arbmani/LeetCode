#include "vector" 
#include "stack"
#include "iostream"

using namespace std;


/**

As the ruler of a kingdom, 
you have an army of wizards at your command.

You are given a 0-indexed integer array strength, 
where strength[i] denotes the strength of the ith wizard. 
For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), 
the total strength is defined as the product of the following two values:

-   The strength of the weakest wizard in the group.

-   The total of all the individual strengths of the wizards in the group.

Return the sum of the total strengths of all contiguous groups of wizards. 
Since the answer may be very large, return it modulo 10**9 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.


*/

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const long long mod = 1e9 + 7;
        int             n   = strength.size();
        
        vector<int> previousSmaller(n), nextSmallerOrEqual(n);
        stack<int>  stac;

        // Find previous strictly smaller element
        for (int i = 0; i < n; i++){
            while (!stac.empty() && strength[stac.top()] >= strength[i]) stac.pop();
            previousSmaller[i] = stac.empty() ? -1 : stac.top();
            stac.push(i);
        }

        while (!stac.empty()) stac.pop();

        // Find the next smaller or equal element
        for (int i = n - 1; i >= 0; i--){   
            while(!stac.empty() && strength[stac.top()] > strength[i]) stac.pop();
            nextSmallerOrEqual[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = (prefixSum[i] + strength[i]) % mod;
        vector<long long> prefixSumOfPrefixSum(n + 2, 0);
        for (int i = 0; i <= n; i++) prefixSumOfPrefixSum[i + 1] = (prefixSumOfPrefixSum[i] + prefixSum[i]) % mod; 
        long long totalStrengthSum = 0;

        for (int i = 0; i < n; i++){
            long long leftChoice    = i - previousSmaller[i];
            long long rightChoice   = nextSmallerOrEqual[i] - i;
            long long rightContribution = (prefixSumOfPrefixSum[nextSmallerOrEqual[i] + 1] - prefixSumOfPrefixSum[i + 1] + mod) % mod;
            long long leftContribution  = (prefixSumOfPrefixSum[i + 1] - prefixSumOfPrefixSum[previousSmaller[i] + 1] + mod) % mod; 

            long long SumOfSubArraySums = (leftChoice * rightContribution - rightChoice * leftContribution) % mod;
            SumOfSubArraySums  = (SumOfSubArraySums + mod) % mod;
            long long currentElementContribution = strength[i] * SumOfSubArraySums % mod;
            totalStrengthSum = (totalStrengthSum + currentElementContribution) % mod;

        }
        return totalStrengthSum;
        
    }
};


class Solution_Wrong {
public:
    // Given any min(wiz) find all possible lens
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<int> left(n), right(n);
        stack<int> stac;
        for (int i = 0; i < n; i++){        // prev strictly smaller
            while (!stac.empty() && strength[stac.top()] >= strength[i]) stac.pop();
            left[i] = stac.empty() ? - 1 : stac.top();
            stac.push(i);
        }

        while (!stac.empty()) stac.pop();

        for (int i = n - 1; i >= 0; i--){   // next strictly larger
            while (!stac.empty() && strength[stac.top()] >= strength[i]) stac.pop();
            right[i] = stac.empty() ? n : stac.top();
            stac.push(i);
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; i++){
            int maxLen = right[i] - left[i] - 1;
            for (int j = 1; j <= maxLen; j++) ans = (ans + (j * strength[i])) % mod;
        }
        return ans;
    }
};



int main(){ 
    Solution s;

    vector<int> strength1 = {1, 3, 1, 2};
    vector<int> strength2 = {5, 4, 6};

    cout << "\nWant : 44\nWas  : " << s.totalStrength(strength1) << endl;
    cout << "\nWant : 213\nWas  : " << s.totalStrength(strength2) << endl;

    return 0;
}