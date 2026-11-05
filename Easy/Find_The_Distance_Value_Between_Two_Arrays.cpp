#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/**

Given two integer arrays arr1 and arr2, 
and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] 
such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

*/

class Solution {
private:
    int binarySearch(const vector<int> arr, int target){
        int left = 0, right = arr.size();
        while (left < right){
            int mid = left + (right - left) / 2;
            if (arr[mid] < target)  left  = mid + 1;
            else                    right = mid;
        }
        return left;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int num : arr1){
            int idx = binarySearch(arr2, num);
            bool valid = true;

            if (idx < arr2.size() && abs(arr2[idx] - num) <= d) valid = false;
            if (idx > 0 && abs(arr2[idx - 1] - num) <= d)       valid = false;   
            if (valid) ans++;
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> arr1_1 = {4,5,8};
    vector<int> arr2_1 = {10,9,1,8};

    vector<int> arr1_2 = {1,4,2,3};
    vector<int> arr2_2 = {-4,-3,6,10,20,30};

    vector<int> arr1_3 = {2,1,100,3};
    vector<int> arr2_3 = {-5,-2,10,-3,7};

    cout << "\nWant : 2\nWas  : " << s.findTheDistanceValue(arr1_1, arr2_1, 2) << endl;
    cout << "\nWant : 2\nWas  : " << s.findTheDistanceValue(arr1_2, arr2_2, 3) << endl;
    cout << "\nWant : 1\nWas  : " << s.findTheDistanceValue(arr1_3, arr2_3, 6) << endl;

    return 0;
}