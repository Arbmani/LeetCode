#include "vector"
#include "iostream"
#include <algorithm>
#include <climits>

using namespace std;

/*

You are given a 2D integer array items, where items[i] = [factori, pricei] 
represents the ith item. You are also given an integer budget.

There are unlimited copies of each item available for purchase.
You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget.

After buying items, you may receive free copies according to the following rules:

-   For each item i that you bought at least one copy of, 
    you receive one free copy of every item j such that j != i and factori divides factorj.

-   Buying multiple copies of the same item i does not give additional free copies through item i.

-   The same item j can be received multiple times for free 
    if it is received from purchases of different item types.

Return the maximum total number of item copies you can obtain, 
including both purchased copies and free copies, while spending at most budget on purchased items.

*/

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int greedyValue = INT_MAX;
        for (const auto& row : items) greedyValue = min(greedyValue, row[1]);

        vector<int> values;
        vector<int> costs;
        for (int i = 0; i < items.size(); i++){
            int factor = items[i][0];
            int cost   = items[i][1];
            int ans    = 1;
            for (int j = 0; j < items.size(); j++){
                if (i == j) continue;
                if (items[j][0] % factor == 0) ans++;
            }
            if (ans * greedyValue > cost){
                values.push_back(ans);
                costs.push_back(items[i][1]);
            }
        }
        
        vector<int> dp(budget + 1, INT_MIN);
        dp[0] = 0;

        for (int i = 0; i < values.size(); i++){
            for (int w = budget; w >= costs[i]; w--){
                if(dp[w - costs[i]] == INT_MIN) continue;
                dp[w] = max(dp[w], dp[w - costs[i]] + values[i]);
            }
        }
        int ans = 0;
        for (int w = 0; w <= budget; w++){
            if (dp[w] == INT_MIN) continue;
            ans = max(ans, dp[w] + (budget - w) / greedyValue);
        }

        return ans;
    }
};


class Solution_ass {
private: 
    int dfs(vector<int>& value, const vector<int>& cost, int budget, int ans){
        if (budget == 0) return ans;
        if (budget <  0) return INT_MIN;
        int newans = ans;
        for(int i = 0; i < value.size(); i++){
            int temp = value[i];
            value[i] = 1;
            newans = max(newans, dfs(value, cost,budget - cost[i], ans + temp));
            value[i] = temp;
        }
        return newans;
}

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> value;
        vector<int> cost;
        int         lowestCost = INT_MAX;
        for (int i = 0; i < items.size(); i++){
            int factor = items[i][0];
            int ans    = 1;
            lowestCost = min(lowestCost, items[i][1]);
            for (int j = 0; j < items.size(); j++){
                if (i == j) continue;
                if (items[j][0] % factor == 0) ans++;
            }
            if (ans > 1){
                value.push_back(ans);
                cost.push_back(items[i][1]);
            }
        }
        return dfs(value, cost, budget, 0);
    }
};

int main(){
    Solution s;

    vector<vector<int>> items1 = {{6, 2}, {2, 6}, {3, 4}};
    vector<vector<int>> items2 = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};

    cout << "\nWant : 4\nWas  : " << s.maximumSaleItems(items1, 9) << endl;
    cout << "\nWant : 10\nWas  : " << s.maximumSaleItems(items2, 8) << endl;


    return 0;
}