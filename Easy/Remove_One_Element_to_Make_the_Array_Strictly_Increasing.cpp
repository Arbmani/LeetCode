#include<vector>
#include<iostream>

using namespace std;

class Solution {
    /**
     *  [Easy Problem]
     *  
     *  Given a 0-indexed integer array nums, return true if it can be made strictly increasing 
     *  after removing exactly one element, or false otherwise. 
     *  If the array is already strictly increasing, return true.
     * 
     *  The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
     * 
     * 
     */
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        int counter = 0;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] <= nums[i - 1]){
                counter++;
                if (counter > 1) return false;
                if (i > 1 && nums[i] <= nums[i - 2]){
                    nums[i] = nums[i - 1];
                } else{
                    nums[i - 1] = nums[i];
                }

            }
        }
        return true;
    }
};


int main(){
    Solution solution;
    vector<int> num0 = {100,21,100};
    vector<int> num1 = {1,2,10,5,7};
    vector<int> num2 = {2,3,1,2};
    vector<int> num3 = {1,1,1};
    cout << "Want : true, Was :" << boolalpha << solution.canBeIncreasing(num0) << endl; 


    cout << "Want : true, Was :" << boolalpha << solution.canBeIncreasing(num1) << endl; 
    cout << "Want : false, Was :" << boolalpha << solution.canBeIncreasing(num2) << endl; 
    cout << "Want : false, Was :" << boolalpha << solution.canBeIncreasing(num3) << endl; 

    return 0;
}