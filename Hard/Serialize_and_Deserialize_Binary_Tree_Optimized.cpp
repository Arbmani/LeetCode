#include "string"
#include "queue"
#include "vector"
#include "iostream"
#include <cstddef>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**

Serialization is the process of converting a data structure or object 
into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later 
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that a binary tree 
can be serialized to a string and this string can be 
deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode 
serializes a binary tree. You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself.

*/

class Codec {
private:
    void dfsSerialize(TreeNode* node, string& ans){
        if (!ans.empty()) ans += ',';
        if (!node) {
            ans += 'N';
            return;
        }
        ans += to_string(node->val);
        dfsSerialize(node->left, ans);
        dfsSerialize(node->right, ans);
    }
    TreeNode* dfsDeserialize(stringstream& ss){
        string value;
        getline(ss, value, ',');
        if (value == "N") return nullptr;
        TreeNode* node = new TreeNode(stoi(value));
        node->left = dfsDeserialize(ss);
        node->right = dfsDeserialize(ss);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string ans;
        dfsSerialize(root, ans);
        return ans;
    }

    TreeNode* deserialize(string data) {
       stringstream ss(data);
       return dfsDeserialize(ss);
    }
};





void printTree(TreeNode* root){
    if (root == nullptr){
        cout << "[]";
        return;
    }
    queue<TreeNode*> que;
    vector<string> result;
    que.push(root);

    while(!que.empty()){
        TreeNode* node = que.front();
        que.pop();

        if (node == nullptr){
            result.push_back("null");
            continue;
        }   
        result.push_back(to_string(node->val));
        que.push(node->left);
        que.push(node->right);
    }

    while(!result.empty() && result.back() == "null"){
        result.pop_back();
    }

    cout << "[";
    for( size_t i = 0; i < result.size(); ++i){
        if (i >0 ) cout << ",";
        cout << result[i];
    }

    cout << "]";
}


int main(){
    Codec codec;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string data = codec.serialize(root);
    TreeNode* decode = codec.deserialize(data);

    cout << "Example 1:" << endl;
    cout << "Input: [1,2,3,null,null,4,5] " << endl;
    cout <<"Output: ";
    printTree(decode);
    cout << endl << endl;

    TreeNode* emptyRoot = nullptr;
    string emptyData = codec.serialize(emptyRoot);
    TreeNode* emptyDecoded = codec.deserialize(emptyData);
    cout << "Example 2:" << endl;
    cout << "Input: []" << endl;
    cout << "Output: ";
    printTree(emptyDecoded);
    cout << endl;
    return 0;
}