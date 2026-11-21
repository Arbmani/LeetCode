#include "vector"
#include "unordered_set"
#include "iostream"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for (int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

/*

There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. 
You are given a 0-indexed integer array parents, 
where parents[i] is the parent for node i. 
Since node 0 is the root, parents[0] == -1.

There are 105 genetic values, each represented by an integer in the inclusive range [1, 105]. 
You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.

Return an array ans of length n where ans[i] is the smallest 
genetic value that is missing from the subtree rooted at node i.

The subtree rooted at a node x contains node x and all of its descendant nodes.


*/


class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int node = -1;
        for (int i = 0; i < n; i++){
            if (nums[i] == 1){
                node = i;
                break;
            }
        }
        if (node == -1) return ans;

        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parents[i]].push_back(i);
        unordered_set<int> seen;
        int missing = 1;

        while(node != -1){
            vector<int> stac = {node};
            while (!stac.empty()){
                int curr = stac.back();
                stac.pop_back();

                if (seen.count(nums[curr])) continue;
                seen.insert(nums[curr]);
                for (int child : children[curr]) stac.push_back(child);
            }
            while(seen.count(missing)) missing++;
            ans[node] = missing;
            node = parents[node];
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> parents1 = {-1,0,0,2};
    vector<int> nums1 = {1,2,3,4};
    vector<int> out1 = {5,1,1,1};

    vector<int> parents2 = {-1,0,1,0,3,3};
    vector<int> nums2 = {5,4,6,2,1,3};
    vector<int> out2 = {7,1,1,4,2,1};

    vector<int> parents3 = {-1,2,3,0,2,4,1};
    vector<int> nums3 = {2,3,4,5,6,7,8};
    vector<int> out3 = {1,1,1,1,1,1,1};

    cout << "\nWant : " << out1 << "\nWas  : " << s.smallestMissingValueSubtree(parents1, nums1) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.smallestMissingValueSubtree(parents2, nums2) << endl;
    cout << "\nWant : " << out3 << "\nWas  : " << s.smallestMissingValueSubtree(parents3, nums3) << endl;


    return 0;
}
