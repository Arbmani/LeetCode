#include "queue"
#include "vector"
#include "functional"

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void dfs(TreeNode * node){
        if (node == nullptr) return;
        minHeap.push(node->val);
        dfs(node->left);
        dfs(node->right);
    }


    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        while (k > 1){
            minHeap.pop();
            k--;
        }
        return minHeap.top();      
    }
};

