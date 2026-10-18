#include "vector"
#include <ostream>
#include <vector>
#include "iostream"
#include "queue"
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for(int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";


    return os;
}

/**

[Medium Problem]

A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between the two nodes ai and bi in the tree, 
you can choose any node of the tree as the root. 
When you select a node x as the root, the result tree has height h. 
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (const auto& edge: edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> leaves;
        for(int index = 0; index < n; index++){
            if (degree[index] == 1){
                leaves.push(index);
            }
        }
        int remaining = n;
        while (remaining > 2){
            int layerSize = leaves.size();
            remaining -=layerSize;

            for(int index = 0; index < layerSize; index++){
                int leaf = leaves.front();
                leaves.pop();
                for(int neighbor : adj[leaf]){
                    degree[neighbor]--;

                    if (degree[neighbor] == 1){
                        leaves.push(neighbor);
                    }
                }
            }
        }
        vector<int> ans;
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<vector<int>> edges1 = {{1,0}, {1, 2}, {1,3}};
    vector<vector<int>> edges2 = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};

    vector<int> output1 = {1};
    vector<int> output2 = {3,4};

    cout << "Want : " << output1 << ", Was : " << s.findMinHeightTrees(4, edges1) << endl;
    cout << "Want : " << output2 << ", Was : " << s.findMinHeightTrees(6, edges2) << endl;

    return -1;
}