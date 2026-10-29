#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

class Solution {
public:
    TreeNode* dfs(TreeNode* node, TreeNode*p, TreeNode*q){
        if(node == nullptr || node == p || node == q) return node;
        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);
        if(left && right) return node;
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }

};