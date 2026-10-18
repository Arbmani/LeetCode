#include "iostream"
#include <cstddef>
#include <tuple>
#include <type_traits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //tuple<TreeNode*, bool, bool> dfs(TreeNode* node, TreeNode*p, TreeNode* q){
    //    if(node == nullptr) return {nullptr, false, false};
    //    auto tuple_left = dfs(node->left, p, q);
    //    auto tuple_right = dfs(node->right, p, q);
    //    bool q_left = get<1>(tuple_left);
    //    bool p_left = get<2>(tuple_left);
    //    bool q_right = get<1>(tuple_right);
    //    bool p_right = get<2>(tuple_right);
//
    //    if(q_left && p_left) return tuple_left;
    //    if(q_right && p_right) return tuple_right;
    //    bool found_q = q_left || q_right || node == q;
    //    bool found_p = p_left || p_right || node == p;
    //    return {node, found_q, found_p};
    //}
//
    //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //    return get<0>(dfs(root, p, q));
    //}

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