#include "vector"
#include "iostream"

using namespace std;

/**

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.


*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0, odd = 0, even = 1;
        const int mod = 1e9 + 7;
        int parity    = 0;

        for (int num : arr){
            parity ^= (num & 1);
            if (parity){
                ans = (ans + even) % mod;
                odd++;
            } else{
                ans = (ans + odd)  % mod;
                even++;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;

    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};

    vector<int> arr4 = {1, 2, 3};
    vector<int> arr5 = {1, 3, 2};
    vector<int> arr6 = {1, 3, 5, 7, 9, 2, 2, 2, 2, 2, 1, 1};
    cout << "\nWant : 4\nWas  : " << s.numOfSubarrays(arr1) << endl;
    cout << "\nWant : 0\nWas  : " << s.numOfSubarrays(arr2) << endl;
    cout << "\nWant : 16\nWas  : " << s.numOfSubarrays(arr3) << endl;

    cout << "\nWant : 4\nWas  : " << s.numOfSubarrays(arr4) << endl;
    cout << "\nWant : 3\nWas  : " << s.numOfSubarrays(arr5) << endl;
    cout << "\nWant : 36\nWas  : " << s.numOfSubarrays(arr6) << endl;

    return 0;
}

/**

    vector<int> arr4 = {1, 2, 2};

        const int mod   = 1e9 + 7;
        //  odd = 0 -> 0
        //  odd = 1 -> len(arr)
        //  odd = 2
        //      {1, 2, 3}   : {1}, {1, 2}, {3}, {2, 3}      
        //      {1, 3, 2}   : {1}, {3}, {3, 2}

        // för 1 odd = len(arr) med bara 1 
        // för X + 1 odd där X % 2 == 0 äre arr(X) nya
        int ans         = 0;
        int oddCounter  = 0;
        int prev        = -1;
        for (int i = 0; i < arr.size(); i++){

 
        }


*/