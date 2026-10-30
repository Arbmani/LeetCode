#include "vector"
#include "iostream"

using namespace std;
/**

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.


*/

class Solution {
private:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };

    TrieNode* root = new TrieNode();
    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            if(!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }
    int findMaxXOR(int num){
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->child[opposite]){
                maxXOR |= (1 << i);
                node = node->child[opposite];
            }
            else node = node->child[bit];
        }
        return maxXOR;
    }


public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int ans = 0;
        for (int num : nums)    insert(num);
        for (int num: nums)     ans = max(ans, findMaxXOR(num));
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {3,10,5,25,2,8};
    vector<int> nums2 = {14,70,53,83,49,91,36,80,92,51,66,70};
    
    cout << "Want :  28, Was : " << s.findMaximumXOR(nums1) << endl;
    cout << "Want : 127, Was : " << s.findMaximumXOR(nums2) << endl;

    return 0;
}