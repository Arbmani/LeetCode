#include "vector"
#include "iostream"
#include "string"
#include <climits>
#include <queue>
#include <tuple>
using namespace std;

/**

You are given an integer n representing the number of nodes in a directed weighted graph, 
numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] 
represents a directed edge from node ui to node vi with weight wi.

You are also given a string labels of length n, 
where labels[i] is the character assigned to node i, and an integer k.

Return the minimum total edge weight of a path from node 0 to node n - 1 
such that the concatenation of the labels of the nodes along the path contains 
at most k consecutive identical characters. If no valid path exists, return -1.

*/

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (k <= 0) return -1;                                          //     <distance, node, consecutiveCount>
        using                                                   State   = tuple<long long, int, int>;                   
        const long long                                         inf     = LLONG_MAX;
        vector<vector<long long>>                               dist(n, vector<long long>(k + 1, inf));
        vector<vector<pair<int, int>>>                          adj(n);
        priority_queue<State, vector<State>, greater<State>>    maxHeap;   
        for (const auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        
        dist[0][1] = 0;
        maxHeap.push({0, 0, 1});

        while(!maxHeap.empty()){
            auto [cost, u, count] = maxHeap.top();
            maxHeap.pop();
            if (cost != dist[u][count]) continue;
            if (u == n - 1)             return static_cast<int>(cost);
            for (auto [v, weight] : adj[u]){
                int nextCount = (labels[u] == labels[v]) ? count + 1 : 1;
                if (nextCount > k) continue;
                long long newCost = cost + weight;
                if (newCost < dist[v][nextCount]){
                    dist[v][nextCount] = newCost;
                    maxHeap.push({newCost, v, nextCount});
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;

    vector<vector<int>> edges1 = {{0,1,1}, {1,2,1}, {0,2,3}};
    vector<vector<int>> edges2 = {{0,1,1}, {1,2,1}, {0,2,3}};
    vector<vector<int>> edges3 = {{0,1,1}, {1,2,1}};

    cout << "Want :  3, Was : " << s.shortestPath(3, edges1, "aab", 1) << endl;
    cout << "Want :  2, Was : " << s.shortestPath(3, edges2, "aab", 2) << endl;
    cout << "Want : -1, Was : " << s.shortestPath(3, edges3, "aaa", 2) << endl;


    return 0;
}