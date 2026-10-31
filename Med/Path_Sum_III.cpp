#include "iostream"
#include <unordered_map>

using namespace std;

/**

Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, 
but it must go downwards (i.e., traveling only from parent nodes to child nodes).

()

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int dfs(TreeNode* node, long long curSum, int targetSum, unordered_map<long long, int>& prefixSums){
        if (!node) return 0;
        curSum += node->val;
        int count = prefixSums[curSum - targetSum];
        prefixSums[curSum]++;
        count += dfs(node->left, curSum, targetSum, prefixSums);
        count += dfs(node->right, curSum, targetSum, prefixSums);
        prefixSums[curSum]--;
        return count;
    }


public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1;
        return dfs(root, 0, targetSum, prefixSums);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Example 1
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(-3);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);
    root1->right->right = new TreeNode(11);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(-2);
    root1->left->right->right = new TreeNode(1);

    cout << "Want : 3, Was : " << sol.pathSum(root1, 8) << endl; // Expected: 3


    // Test Case 2: Example 2
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(11);
    root2->right->left = new TreeNode(13);
    root2->right->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(7);
    root2->left->left->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(5);
    root2->right->right->right = new TreeNode(1);

    cout << "Want : 3, Was : " <<  sol.pathSum(root2, 22) << endl; // Expected: 3


    // Test Case 3: Single node
    TreeNode* root3 = new TreeNode(8);

    cout << "Want : 1, Was : " <<  sol.pathSum(root3, 8) << endl; // Expected: 1


    // Test Case 4: No valid path
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);

    cout << "Want : 0, Was : " <<  sol.pathSum(root4, 10) << endl; // Expected: 0


    // Test Case 5: Negative values
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(3);

    cout << "Want : 1, Was : " <<  sol.pathSum(root5, -1) << endl; // Expected: 1


    // Test Case 6: Multiple paths ending at different nodes
    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(1);
    root6->right = new TreeNode(1);
    root6->left->left = new TreeNode(1);
    root6->left->right = new TreeNode(1);

    cout << "Want : 4, Was : " <<  sol.pathSum(root6, 2) << endl; // Expected:4


    // Test Case 7: Path starts below the root
    TreeNode* root7 = new TreeNode(10);
    root7->left = new TreeNode(2);
    root7->right = new TreeNode(3);
    root7->left->left = new TreeNode(6);

    cout << "Want : 1, Was : " <<  sol.pathSum(root7, 8) << endl; // Expected: 1


    // Test Case 8: Zero values
    TreeNode* root8 = new TreeNode(0);
    root8->left = new TreeNode(0);
    root8->right = new TreeNode(0);

    cout << "Want : 5, Was : " <<  sol.pathSum(root8, 0) << endl; // Expected: 5

    return 0;
}