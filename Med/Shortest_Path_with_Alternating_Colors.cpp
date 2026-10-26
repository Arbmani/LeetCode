#include "vector"
#include "iostream"
#include <queue>
#include <vector>
using namespace std;


template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int index = 0; index < vec.size(); index++){
        os << vec[index];
        if(index + 1 < vec.size()) os << ", ";
    }
    os << "]";


    return os;
} 

/**

You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. 
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

-   redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and

-   blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

Return an array answer of length n, where each answer[x] is the length 
of the shortest path from node 0 to node x such that the edge colors 
alternate along the path, or -1 if such a path does not exist.



*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        queue<vector<int>>  que;
        vector<int>         ans(n, -1);

        for (const auto& edge : redEdges )  red[edge[0]].push_back(edge[1]);
        for (const auto& edge : blueEdges) blue[edge[0]].push_back(edge[1]);

        que.push({0, 0, -1});
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][0] = true;
        visited[0][1] = true;

        while(!que.empty()) {
            vector<int> state = que.front();
            que.pop();

            int node            = state[0];
            int distance        = state[1];
            int previouscolor   = state[2];

            if (ans[node] == -1)  ans[node] = distance;
            if (previouscolor != 0) {
                for (int neighbor : red[node]) {
                    if(!visited[neighbor][0]){
                        visited[neighbor][0] = true;
                        que.push({neighbor, distance + 1, 0});
                    }
                }
            }
            if (previouscolor != 1) {
                for (int neighbor : blue[node]) {
                    if(!visited[neighbor][1]){
                        visited[neighbor][1] = true;
                        que.push({neighbor, distance + 1, 1});
                    }
                }
            }
        }

        return ans;      
    }
};


int main(){
    Solution s;

    vector<vector<int>> redEdges1   = {{0,1}, {1, 2}};
    vector<vector<int>> blueEdges1  = {};
    vector<vector<int>> redEdges2   = {{0, 1}};
    vector<vector<int>> blueEdges2  = {{2,1}};

    vector<int> out1 = {0, 1, -1};
    vector<int> out2 = {0, 1, -1};

    cout << "Want : " << out1 << ", Was : " << s.shortestAlternatingPaths(3, redEdges1, blueEdges1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.shortestAlternatingPaths(3, redEdges2, blueEdges2) << endl;



    return 0;
}