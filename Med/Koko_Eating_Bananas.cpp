#include "iostream"
#include "vector"
#include "algorithm"
#include <algorithm>


using namespace std;

/**

Koko loves to eat bananas. There are n piles of bananas, 
the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



*/


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right){
            int mid     = left + (right - left) / 2;
            int hours   = 0;

            for (int pile : piles)  hours += (pile + mid -1) / mid;
            
            if (hours <= h) right = mid;
            else            left  = mid + 1; 
        }
        return left;
    }
};

int main(){
    Solution s;

    vector<int> piles1 = {3,6,7,11};
    vector<int> piles2 = {30,11,23,4,20};
    vector<int> piles3 = {30,11,23,4,20};

    cout << "Want :  4, Was : " << s.minEatingSpeed(piles1, 8) << endl;
    cout << "Want : 30, Was : " << s.minEatingSpeed(piles2, 5) << endl;
    cout << "Want : 23, Was : " << s.minEatingSpeed(piles3, 6) << endl;


    return -1;
}