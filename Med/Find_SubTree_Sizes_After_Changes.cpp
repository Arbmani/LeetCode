#include "vector"
#include "string"
#include "iostream"
#include <vector>
#include <array>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i < vec.size() - 1) os << ", ";

    }
    os << "]";

    return os;
}

/*

You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. 
The tree is represented by an array parent of size n, 
where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

We make the following changes on the tree one time simultaneously for all nodes x from 1 to n - 1:

Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
If node y does not exist, do nothing.
Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.
Return an array answer of size n where answer[i] is the size of the subtree rooted at node i in the final tree.



*/




class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int nodes = parent.size();
        vector<vector<int>> children(nodes);
        for (int node = 1; node < nodes; node++) children[parent[node]].push_back(node);
        
        vector<int> ans(nodes, 1);
        vector<int> previousAncestor(nodes);
        array<int, 26> lastSeen;
        lastSeen.fill(-1);
        vector<int> stac = {0};


        while (!stac.empty()){
            int node = stac.back();
            stac.pop_back();

            if (node >= 0){
                int cha = s[node] - 'a';
                previousAncestor[node] = lastSeen[cha];
                lastSeen[cha] = node;
                stac.push_back(~node);
                for (int child : children[node]) stac.push_back(child);
            } else{
                node = ~node;
                int cha = s[node] - 'a';
                lastSeen[cha] = previousAncestor[node];
                if (node != 0){
                    int newParent = previousAncestor[node];
                    if (newParent == -1) newParent = parent[node];
                    ans[newParent] += ans[node];
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s = Solution();

    vector<int> parent1 = {-1,0,0,1,1,1};
    vector<int> out1 = {6,3,1,1,1,1};
    vector<int> parent2 = {-1,0,4,0,1};
    vector<int> out2 = {5,2,1,1,1};

    cout << "\nWant : " << out1 << "\nWas  : " << s.findSubtreeSizes(parent1, "abaabc") << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.findSubtreeSizes(parent2, "abbba") << endl;

}