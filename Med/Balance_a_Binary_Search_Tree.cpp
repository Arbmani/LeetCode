#include "iostream"
#include "vector"
#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**

Given the root of a binary search tree, return a balanced binary search tree 
with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


*/

class Solution {
private:
    vector<TreeNode*> nodes;
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    TreeNode* build(int left, int right){
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = nodes[mid];
        root->left  = build(left, mid - 1);
        root->right = build(mid + 1, right);
        return root; 
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1); // TODO
    }
};

