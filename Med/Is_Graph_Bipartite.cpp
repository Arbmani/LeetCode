#include "vector"
#include "queue"
#include "iostream"
#include <queue>

using namespace std;

/**

There is an undirected graph with n nodes, 
where each node is numbered between 0 and n - 1.
You are given a 2D array graph, where graph[u] 
is an array of nodes that node u is adjacent to. 
More formally, for each v in graph[u], there is an undirected 
edge between node u and node v. The graph has the following properties:

-   There are no self-edges (graph[u] does not contain u).

-   There are no parallel edges (graph[u] does not contain duplicate values).

-   If v is in graph[u], then u is in graph[v] (the graph is undirected).

-   The graph may not be connected, meaning there may be two 
    nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B 
such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> odd(n, 0);

        auto bfs = [&](int start) -> bool {
            if (odd[start]) return true;
            queue<int> que;
            que.push(start);
            odd[start] = -1;
            while(!que.empty()){
                int node = que.front();
                que.pop();

                for (int nei : graph[node]){
                    if (odd[node] == odd[nei]) return false;
                    else if (!odd[nei]){
                        que.push(nei);
                        odd[nei] = -1 * odd[node];
                    }
                }
            }
            return true;
        };

        for (int node = 0; node < n; node++) if(!bfs(node)) return false;
        return true;
    }
};

int main(){
    Solution s;

    vector<vector<int>> graph1 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    vector<vector<int>> graph2 = {{1,3}, {0,2}, {1,3}, {0,2}};

    cout << "Want : false, Was : " << boolalpha <<s.isBipartite(graph1) << endl;
    cout << "Want :  true, Was : " << boolalpha <<s.isBipartite(graph2) << endl;

    return 0;
}