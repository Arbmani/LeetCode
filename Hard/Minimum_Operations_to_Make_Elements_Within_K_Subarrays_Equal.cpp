#include "set"
#include "vector" 
#include "iostream"
#include <climits>
using namespace std;

template <typename T> 
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int i = 0; i < v.size(); i++){
        os << v[i];
        if (i + 1 < v.size()) os << ", ";

    }
    os << "]";
    return os;
}


/**

You are given an integer array nums and two integers, x and k. 
You can perform the following operation any number of times (including zero):

-   Increase or decrease any element of nums by 1.

Return the minimum number of operations needed to have at least k non-overlapping 
subarrays of size exactly x in nums, where all elements within each subarray are equal.

*/
class Solution {
private:
    vector<long long> calculateWindowCosts(const vector<int>& nums, int windowSize){
        long long       smallerSum = 0, largerSum = 0;
        multiset<int>   smallerHalf,    largerHalf;
        vector<long long> costs;

        auto balanceHalves = [&](){
            while (smallerHalf.size() > largerHalf.size() + 1){
                auto it = prev(smallerHalf.end());
                int value = *it;
                smallerHalf.erase(it);
                smallerSum -= value;

                largerHalf.insert(value);
                largerSum += value;                
            }

            while (smallerHalf.size() < largerHalf.size()){
                auto it = largerHalf.begin();
                int value = *it;

                largerHalf.erase(it);
                largerSum -= value;

                smallerHalf.insert(value);
                smallerSum += value;
            }
        };

        auto insertElement = [&](int value){
            if (smallerHalf.empty() || value <= *prev(smallerHalf.end())){
                smallerHalf.insert(value);
                smallerSum += value;
            } else{
                largerHalf.insert(value);
                largerSum += value;
            }
            balanceHalves();
        };
        auto removeElement = [&](int value){
            auto it = smallerHalf.find(value);
            if (it != smallerHalf.end()){
                smallerHalf.erase(it);
                smallerSum -= value;
            }
            else {
                it = largerHalf.find(value);
                largerHalf.erase(it);
                largerSum -= value;
            }
            balanceHalves();
        };
        for (int index = 0; index < nums.size(); index++){
            insertElement(nums[index]);
            if (index >= windowSize) removeElement(nums[index - windowSize]);
            if (index >= windowSize - 1){
                long long median = *prev(smallerHalf.end());
                long long cost   = median * smallerHalf.size() - smallerSum + 
                                    largerSum - median * largerHalf.size();
                costs.push_back(cost);
            }
        }
        return costs;
    }


public:
    long long minOperations(vector<int>& nums, int windowSize, int k) {
        vector<long long> costs = calculateWindowCosts(nums, windowSize);
        const long long inf = LLONG_MAX / 4;
        int n = nums.size();
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, inf);

        for (int selectedWindow = 1; selectedWindow <= k; selectedWindow++){
            fill(curr.begin(), curr.end(), inf);
            for (int elementsConsidered = selectedWindow * windowSize; elementsConsidered <= n; elementsConsidered++){
                curr[elementsConsidered] = curr[elementsConsidered - 1];
                int windowStart = elementsConsidered - windowSize;

                long long candidate = prev[windowStart] + costs[windowStart];
                curr[elementsConsidered] = min(curr[elementsConsidered], candidate);
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};



class Solution_TLE {
private:    // maybe we also track total cost for each median after
    vector<double> slidingWindowMedian(const vector<int>& nums, int windowSize){
        multiset<int> smallerHalf;
        multiset<int> largerHalf;
        vector<double> medians;
        auto balanceHalves = [&](){
            while (smallerHalf.size() > largerHalf.size() + 1){
                auto largestInSmallerHalf = prev(smallerHalf.end());
                largerHalf.insert(*largestInSmallerHalf);
                smallerHalf.erase(largestInSmallerHalf);
            }   
            while (smallerHalf.size() < largerHalf.size()){
                auto smallestInLargerHalf = largerHalf.begin();
                smallerHalf.insert(*smallestInLargerHalf);
                largerHalf.erase(smallestInLargerHalf);
            }
        };

        for (int index = 0; index < nums.size(); index++){
            int incomingElement = nums[index];
            if (smallerHalf.empty() || incomingElement <= *prev(smallerHalf.end())) 
                smallerHalf.insert(incomingElement);
            else
                largerHalf.insert(incomingElement);
            balanceHalves();

            if (index >= windowSize){
                int outgoingElement = nums[index - windowSize];
                auto elementToRemove = smallerHalf.find(outgoingElement);
                if (elementToRemove != smallerHalf.end()) smallerHalf.erase(elementToRemove);
                else{
                    elementToRemove = largerHalf.find(outgoingElement);
                    largerHalf.erase(elementToRemove);
                }
                balanceHalves();
            }
            if (index >= windowSize - 1){
                medians.push_back(*prev(smallerHalf.end()));
            }
        }
        return medians;
    }

public:
    // maxheap with K 
    // if new median we recompute cost for window size, 
    // if cost lower than maxheap push it to heap and pop 
    // the heap 
    long long minOperations(vector<int>& nums, int windowSize, int k) {
        vector<double> medians = slidingWindowMedian(nums, windowSize);
        vector<long long> costs;
        int n = nums.size();
        for (int start = 0; start <= n - windowSize; start++){
            double median = medians[start];
            long long cost = 0;
            for (int end = start; end < start + windowSize; end++){
                cost += abs(nums[end] - median);
            }
            costs.push_back(cost);
        }
        const long long inf = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, inf);

        for (int selectedWindows = 1; selectedWindows <= k; selectedWindows++){
            fill(curr.begin(), curr.end(), inf);
            for (int elementsConsidered = 1; elementsConsidered <= n; elementsConsidered++){
                curr[elementsConsidered] = curr[elementsConsidered - 1];
                if (elementsConsidered >= windowSize){
                    int windowStart = elementsConsidered - windowSize;
                    if (prev[windowStart] != inf){
                        long long cost = prev[windowStart] + costs[windowStart];
                        curr[elementsConsidered] = min(curr[elementsConsidered], cost);
                    }
                }
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {5,-2,1,3,7,3,6,4,-1};
    vector<int> nums2 = {9,-2,-2,-2,1,5};

    //cout << "Medians of nums1 are " << s.slidingWindowMedian(nums1, 3) << endl;
    //cout << "Medians of nums2 are " << s.slidingWindowMedian(nums2, 2) << endl;

    cout << "Want : 8, Was : " << s.minOperations(nums1, 3, 2) << endl;
    cout << "Want : 3, Was : " << s.minOperations(nums2, 2, 2) << endl;

    return 0;
}