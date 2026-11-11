#include "vector"
#include "iostream"
#include <queue>



using namespace std;

/**

You are given an array nums of positive integers. 
In one operation, you can choose any number from nums and 
reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)

Return the minimum number of operations to reduce the sum of nums by at least half.


*/

class Solution {
public:

    // MaxHeap Solution
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxHeap;
        double  sum         = 0.0;
        for (int num : nums){
            sum += num;
            maxHeap.push(num);
        }

        double  target      = sum / 2.0;
        double  reduced     = 0.0;
        int     operations  = 0; 

        while (reduced < target){
            double largest = maxHeap.top() / 2.0;
            maxHeap.pop();
            reduced += largest;
            maxHeap.push(largest);
            operations++;
        }

        return operations;     
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {5, 19, 8, 1};
    vector<int> nums2 = {3, 8, 20};

    cout << "\nWant : 3\nWas  : " << s.halveArray(nums1) << endl;
    cout << "\nWant : 3\nWas  : " << s.halveArray(nums2) << endl;
 

    return 0;
}