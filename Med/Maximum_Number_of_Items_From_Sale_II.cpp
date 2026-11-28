#include "vector"
#include "iostream"
#include <climits>
#include <unordered_map>
#include <algorithm>


using namespace std;

/*

You are given a 2D integer array items, where items[i] = [factori, pricei] 
represents the ith item. You are also given an integer budget.

There are unlimited copies of each item available for purchase. 
You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget.

After buying items, you may receive free copies according to the following rules:

Each purchased copy of item i can give you at most one free copy of another item j.
The free item must satisfy i != j and factori divides factorj.
For each ordered pair (i, j), you can receive a free copy of item j from purchases of item i at most once, 
regardless of how many copies of item i you buy.

The same item j can be received multiple times for free if it is received from purchases of different item types.
Return the maximum total number of item copies you can obtain, 
including both purchased copies and free copies, while spending at most budget on purchased items.




*/

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        unordered_map<int, int> freq;
        unordered_map<int, int> seenCost;
        int maxFactor = INT_MIN;
        int minCost   = INT_MAX;
        for (auto const & row : items){
            freq[row[0]]++;
            maxFactor = max(maxFactor, row[0]);
            minCost   = min(minCost,   row[1]);
        }
        vector<vector<int>> costs;

        for (int i = 0; i < items.size(); i++){
            int factor = items[i][0];
            int cost   = items[i][1];
            int count  = -1;
            if (cost >= 2* minCost || (seenCost.count(cost) && (costs[seenCost[cost]][1] >= budget / cost))) continue;
            for (int multiple = factor; multiple <= maxFactor; multiple += factor){
                count += freq[multiple];
            }
            if (seenCost.count(cost) && count > 0) costs[seenCost[cost]][1] += count;
            else if (count > 0){
                seenCost[cost] = costs.size();
                costs.push_back({cost, count});
            }
        }
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        int ans   = 0;
        int index = 0;

        while(budget >= 0 && index < costs.size()){
            int cost = costs[index][0];
            if (cost > budget) break;
            int times = min(costs[index][1], budget / cost);
            budget -= (cost * times);
            ans    += 2 * times;
            index++;
        }
        if (budget != 0) ans += budget / minCost;


        return ans;
    }
};


class Solution_WAYTOSLOW {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int greedyValue = INT_MAX;
        for (const auto & row : items) greedyValue = min(greedyValue, row[1]);

        vector<int> values;
        vector<int> costs;

        for (int i = 0; i < items.size(); i++){
            int factor = items[i][0];
            int cost   = items[i][1];
            for (int j = 0; j < items.size(); j++){
                if (j == i) continue;
                if (items[j][0] % factor == 0){
                    if(2 * greedyValue > cost){
                        values.push_back(2);
                        costs.push_back(items[i][1]);
                    }
                }
            }
        }

        vector<int> dp(budget + 1, 0);
        

        for (int i = 0; i < values.size(); i++){
            int value = values[i];
            int cost  = costs[i];

            for (int sum = budget; sum >= cost; sum--){
                dp[sum]  = max(dp[sum], dp[sum - cost] + value);
            }
        }
        int ans = 0;
        for (int sum = budget; sum >= 0; sum--){
            ans = max(ans, dp[sum] + (budget - sum) / greedyValue);
        }

        return ans;
    }
};


int main(){
    Solution s;
    
    vector<vector<int>> items1 = {{1,6}, {2, 4}, {3, 5}};
    vector<vector<int>> items2 = {{2, 8}, {1, 10}, {6, 6}, {4, 12}, {5, 20}, {5, 17}};

    cout << "\nWant : 5\nWas  : " << s.maximumSaleItems(items1, 19) << endl;
    cout << "\nWant : 7\nWas  : " << s.maximumSaleItems(items2, 35) << endl;


    return -1;
}