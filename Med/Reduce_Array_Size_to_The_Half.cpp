#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

/**

You are given an integer array arr. You can choose a set of integers 
and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at 
least half of the integers of the array are removed.


*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        vector<int> counts;
        for (int num : arr) freq[num]++;
        for (auto & [num, count] : freq) counts.push_back(count);
        sort(counts.rbegin(), counts.rend());
        int removed = 0;
        int result  = 0;
        int target  = (arr.size() + 1) / 2;

        for (int count : counts){
            if (removed >= target) break;
            removed += count;
            result++;
        }
        return result;
    }
};

int main(){
    Solution s;

    vector<int> arr1 = {3,3,3,3,5,5,5,2,2,7};
    vector<int> arr2 = {7,7,7,7,7,7};

    cout << "\nWant : 2\nWas  : " << s.minSetSize(arr1) << endl;
    cout << "\nWant : 1\nWas  : " << s.minSetSize(arr2) << endl;


    return 0;
}