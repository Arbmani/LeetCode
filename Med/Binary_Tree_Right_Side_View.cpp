#include "vector"
#include "iostream"
#include <cstddef>
#include <ostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for (int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";

    return os;
}

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& nums, int depth){
        if (node == nullptr) return;
        if (depth >= nums.size()) nums.push_back(node->val);
        dfs(node->right, nums, depth +1);
        dfs(node->left, nums, depth +1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        
        return ans;        
    }
};



int main(){
    Solution s;
    vector<int> test = {1, 3, 4};
    cout << test << endl;

    return -1;
}
