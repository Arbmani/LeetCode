#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
/**
 *  [Easy Problem]
 *      
 * 
 *  Given an array of integers arr, return true if and only if it is a valid mountain array.

    Recall that arr is a mountain array if and only if:

    -   arr.length >= 3
    -   There exists some i with 0 < i < arr.length - 1 such that:
        
        -   arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        
        -   arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 */
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int left = 0, right = arr.size() - 1;

        while(left < right){
            if (arr[left + 1] > arr[left] and (arr[right - 1] > arr[right])){
                left++;
                right--;
            }
            else if (arr[left + 1] > arr[left]) left++;
            else if (arr[right - 1] > arr[right]) right --;
            else return false;
        }
        if (left == 0 or right == arr.size() -1) return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr1= {2,1};
    vector<int> arr2= {3,5,5};
    vector<int> arr3= {0,3,2,1};

    cout << "Want : false, Was : " <<boolalpha <<  sol.validMountainArray(arr1) << endl;
    cout << "Want : false, Was : " <<boolalpha <<  sol.validMountainArray(arr2) << endl;
    cout << "Want : true, Was : " << boolalpha << sol.validMountainArray(arr3) << endl;


    return -1;
}