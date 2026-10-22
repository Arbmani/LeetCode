#include "iostream"
#include <queue>
#include <vector>
#include <climits>

using namespace std;

/**

You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }

        const int INF = INT_MAX;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        while(!minHeap.empty()){
            auto [time, u] = minHeap.top();
            minHeap.pop();

            if(time > dist[u]) continue;
            for(const auto& [v, weight] : adj[u]){
                int newTime = time + weight;
                if (newTime < dist[v]){
                    dist[v] = newTime;
                    minHeap.push({newTime, v});
                }
            }
        }
        int ans = 0;

        for(int index = 1; index <= n; index++){
            if (dist[index] == INF) return -1;
            ans = max(ans, dist[index]);
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<vector<int>> times1 = {{2,1,1},{2,3,1}, {3,4,1}};
    vector<vector<int>> times2 = {{1,2,1}};
    vector<vector<int>> times3 = {{1,2,1}};

    cout << "Want :  2, Was : " << s.networkDelayTime(times1, 4, 2) << endl;
    cout << "Want :  1, Was : " << s.networkDelayTime(times2, 2, 1) << endl;
    cout << "Want : -1, Was : " << s.networkDelayTime(times1, 2, 2) << endl;

    return -1;
}