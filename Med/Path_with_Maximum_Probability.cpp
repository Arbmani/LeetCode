#include "vector"
#include "queue"
#include "utility"

#include "iostream"
#include <queue>

using namespace std;

/**
You are given an undirected weighted graph of n nodes (0-indexed), 
represented by an edge list where edges[i] = [a, b] is an 
undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum
probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. 
Your answer will be accepted if it differs from the correct answer by at most 1e-5.

*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>>   adj(n);
        priority_queue<pair<double, int>>   maxHeap;
        vector<double>                      bestProb(n, 0.0);

        for (int index = 0; index < edges.size(); index++){
            adj[edges[index][0]].push_back({edges[index][1], succProb[index]});
            adj[edges[index][1]].push_back({edges[index][0], succProb[index]});
        }

        bestProb[start_node] = 1.0;
        maxHeap.push({1.0, start_node});

        while(!maxHeap.empty()){
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            if (prob < bestProb[node]) continue;
            if (node == end_node) return prob;
            
            for (const auto& [nei, edgeProb] : adj[node]){
                double newProb = prob * edgeProb;
                if (newProb > bestProb[nei]){
                    bestProb[nei] = newProb;
                    maxHeap.push({newProb, nei});
                }
            }
        }
        return 0.0;
    }
};


int main(){
    Solution s;

    vector<vector<int>> edges1      = {{1,0}, {1,2}, {0,2}};
    vector<double>      succProb1   = {0.5,0.5,0.2};

    vector<vector<int>> edges2      = {{0,1}, {1,2}, {0,2}};
    vector<double>      succProb2   = {0.5,0.5,0.3};

    vector<vector<int>> edges3      = {{0,1}};
    vector<double>      succProb3   = {0.5};

    cout << "Want : 0.25000, Was : " << s.maxProbability(3, edges1, succProb1, 0, 2) << endl;
    cout << "Want : 0.30000, Was : " << s.maxProbability(3, edges2, succProb2, 0, 2) << endl;
    cout << "Want : 0.00000, Was : " << s.maxProbability(3, edges3, succProb3, 0, 2) << endl;


    return 0;
}