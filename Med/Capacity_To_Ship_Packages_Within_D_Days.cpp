#include "vector"
#include "iostream"
#include <algorithm>
#include <numeric>

using namespace std;

/**

A conveyor belt has packages that must be shipped 
from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result 
in all the packages on the conveyor belt being shipped within days days.

*/

class Solution {
private:
    bool canShip(vector<int>& weights, int capacity, int days){
        int daysNeeded = 1, currentLoad = 0;

        for (int weight : weights){
            if (currentLoad + weight > capacity){
                daysNeeded++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return daysNeeded <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left    = *max_element(weights.begin(), weights.end());
        int right   =  accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right){
            int mid = left + (right - left) / 2;

            if (canShip(weights, mid, days))    right = mid;
            else                                            left  = mid + 1;
        }
        return left;
    }
};

int main(){
    Solution s;

    vector<int> weights1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> weights2 = {3,2,2,4,1,4};
    vector<int> weights3 = {1,2,3,1,1};

    cout << "Want : 15, Was : " << s.shipWithinDays(weights1, 5) << endl;
    cout << "Want :  6, Was : " << s.shipWithinDays(weights2, 3) << endl;
    cout << "Want :  3, Was : " << s.shipWithinDays(weights3, 4) << endl;


    return 0;
}