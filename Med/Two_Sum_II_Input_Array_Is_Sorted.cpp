#include "vector"
#include "iostream"

using namespace std;

/**

You are given a 1-indexed array of integers numbers 
that is already sorted in non-decreasing order.

Find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.



*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int curr_sum = numbers[left] + numbers[right];
            if (curr_sum == target){
                return {left + 1, right + 1};
            }
            else if (curr_sum < target) {
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};

template <typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", "; 
    }
    os << "]";

    return os;
}

int main(){
    Solution s;
    vector<int> numbers1 = {2,7,11,15};
    vector<int> numbers2 = {2,3,4};
    vector<int> numbers3 = {-1,0};

    vector<int> out1 = {1,2};
    vector<int> out2 = {1,3};
    vector<int> out3 = {1,2};

    cout << "Want : " << out1 << ", Was : " << s.twoSum(numbers1, 9) << endl;
    cout << "Want : " << out2 << ", Was : " << s.twoSum(numbers2, 6) << endl;
    cout << "Want : " << out3 << ", Was : " << s.twoSum(numbers3, -1) << endl;



    return 0;
}