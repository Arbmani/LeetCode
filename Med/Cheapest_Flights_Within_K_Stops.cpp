#include "vector"
#include "iostream"
#include "climits"
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/**

There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [from_i, to_i, price_i] indicates 
that there is a flight from city from_i to city to_i with cost price_i.

You are also given three integers src, dst, and k, 
return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& flight : flights){
            // source       = flight[0], 
            // destination  = flight[1], 
            // price        = flight[2]
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> minHeap;
        minHeap.push({0, src, 0});

        vector<vector<int>> best(n, vector<int>(k + 2, INT_MAX));
        best[src][0] = 0;

        while(!minHeap.empty()){
            auto [price, destination, k_used] = minHeap.top();
            minHeap.pop();

            if (price != best[destination][k_used]) continue;
            if (destination == dst) return price;
            if (k_used > k) continue;
            k_used++;
            for (auto [nextDestination, nextPrice] : graph[destination]){
                nextPrice += price;
                if (nextPrice < best[nextDestination][k_used]){
                    best[nextDestination][k_used] = nextPrice;
                    minHeap.push({nextPrice, nextDestination, k_used});
                }
            }
        }

        return -1;
    }


    // Bellman-Ford
    int findCheapestPrice_slow(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for(int index = 0; index <= k; index++){
            vector<int> newPrices = prices;
            for (auto& flight : flights){
                int source = flight[0], destination = flight[1], price = flight[2];
                if (prices[source] == INT_MAX) continue;
                newPrices[destination] = min(newPrices[destination], prices[source] + price);
            }
            prices = newPrices;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];      
    }
};



int main(){
    Solution s;
    vector<vector<int>> flights1 = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};
    vector<vector<int>> flights2 = {{0,1,100}, {1,2,100}, {0,2,500}};
    vector<vector<int>> flights3 = {{0,1,100}, {1,2,100}, {0,2,500}};
    
    cout << "Want : 700, Was : " << s.findCheapestPrice(4, flights1, 0, 3, 1) << endl;
    cout << "Want : 200, Was : " << s.findCheapestPrice(3, flights2, 0, 2, 1) << endl;
    cout << "Want : 500, Was : " << s.findCheapestPrice(3, flights3, 0, 2, 0) << endl;

    return 0;
}