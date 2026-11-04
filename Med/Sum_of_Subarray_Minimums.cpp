#include "vector"
#include "iostream"

using namespace std;

/**

Given an array of integers arr, find the sum of min(b), 
where b ranges over every (contiguous) subarray of arr. 

Since the answer may be large, return the answer modulo 10^9 + 7.

*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = 1e9 + 7;
        int             n   = arr.size();

        vector<int> left(n), right(n);
        vector<int> stac;

        for (int i = 0; i < n; i++){
            while(!stac.empty() && arr[stac.back()] >= arr[i]) stac.pop_back();
            left[i] = stac.empty() ? i + 1 : i - stac.back();
            stac.push_back(i);
        }
        stac.clear();

        for(int i = n - 1; i >= 0; i--){
            while(!stac.empty() && arr[stac.back()] > arr[i]) stac.pop_back();
            right[i] = stac.empty() ? n - i : stac.back() - i;
            stac.push_back(i);
        }   

        long long ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> arr1 = {3,1,2,4};
    vector<int> arr2 = {11,81,94,43,3};

    cout << "\nWant : 17\nWas  : " << s.sumSubarrayMins(arr1) << endl;
    cout << "\nWant : 444\nWas  : " << s.sumSubarrayMins(arr2) << endl;

    return 0;
}