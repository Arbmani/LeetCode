#include "vector"
#include "numeric"
#include "unordered_map"
#include "iostream"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int index = 0; index < vec.size(); index++){
        os << vec[index];
        if (index + 1 < vec.size()) os << ", ";
    }
    os << "]";

    return os;
}

/**

There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, 
where edges[i] = [ui, vi, wi] indicates that there 
is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. 
The walk starts and ends with a vertex, and each edge connects 
the vertex that comes before it and the vertex that comes after it. 
It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v
is defined as the bitwise AND of the weights of the edges 
traversed during the walk. In other words, 
if the sequence of edge weights encountered during the walk 
is w0, w1, w2, ..., wk, then the cost is 
calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. 
For each query, you need to find the minimum cost of the walk 
starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

*/

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int nodes) : parent(nodes), rank(nodes, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node){
        while (node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;

        if (rank[rootA] > rank[rootB]){
            parent[rootB] = rootA;
            rank[rootA]  += rank[rootB];
        }
        else{
            parent[rootA] = rootB;
            rank[rootB]  += rank[rootA];
        }
        return true;
    }

};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, int> componentCost;
        vector<int> result;
        UnionFind uf(n);
        result.reserve(query.size());

        for (const auto& edge : edges) uf.unite((edge[0]), edge[1]);
        for (const auto& edge : edges){
            int u       = edge[0];
            int weight  = edge[2];
            int root    = uf.find(u);
            if (componentCost.find(root) == componentCost.end())    componentCost[root] = weight;
            else                                                    componentCost[root] &= weight;
        }

        
        for (const auto& quer : query){
            int src = quer[0];
            int dst = quer[1];
            int root1 = uf.find(src);
            int root2 = uf.find(dst);
            if (root1 != root2) result.push_back(-1);
            else                result.push_back(componentCost[root1]);
        }

        return result;
    }
};


int main(){
    Solution s;

    vector<vector<int>> edges1 = {{0,1,7}, {1,3,7}, {1,2,1}};
    vector<vector<int>> query1 = {{0,3}, {3,4}};

    vector<vector<int>> edges2 = {{0,2,7}, {0,1,15}, {1,2,6}, {1,2,1}};
    vector<vector<int>> query2 = {{1,2}};

    vector<int> out1 = {1, -1};
    vector<int> out2 = {0};

    cout << "Want : " << out1 << ", Was : " << s.minimumCost(5, edges1, query1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.minimumCost(3, edges2, query2) << endl;

    return 0;
}