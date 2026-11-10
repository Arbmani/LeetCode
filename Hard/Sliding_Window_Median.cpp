#include "vector"
#include "iostream"
#include "set"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

/**

The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle values.

-   For examples, if arr = [2,3,4], the median is 3.

-   For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. 
There is a sliding window of size k which is moving from the very 
left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.


*/

class Solution {
private:
    multiset<int> large;
    multiset<int> small;

    void balance(){
        while (small.size() > large.size() + 1){
            auto it = prev(small.end());
            large.insert(*it);
            small.erase(it);
        }
        while (small.size() < large.size()){
            auto it = large.begin();
            small.insert(*it);
            large.erase(it);
        }
    }

    void insert(int num){
        if (small.empty() || num <= *small.rbegin())    small.insert(num);
        else                                            large.insert(num);
        balance();
    }

    void erase(int num){
        auto it = small.find(num);
        if (it != small.end()) small.erase(it);
        else {
            it = large.find(num);
            large.erase(it);
        }
        balance();
    }

    double getMedian(){
        if (small.size() > large.size()) return *small.rbegin();
        return ((double)*small.rbegin() + *large.begin()) / 2.0;
    }



public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        small.clear();
        large.clear();
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++){
            insert(nums[i]);
            if (i >= k - 1){
                ans.push_back(getMedian());
                erase(nums[i - k + 1]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    vector<int> nums2 = {1,2,3,4,2,3,1,4,2};

    vector<double> outs1 = {1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000};
    vector<double> outs2 = {2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000};

    cout <<"\nWant : " << outs1 << "\nWas  : " << s.medianSlidingWindow(nums1, 3) << endl;
    cout <<"\nWant : " << outs2 << "\nWas  : " << s.medianSlidingWindow(nums2, 3) << endl;


    return 0;
}