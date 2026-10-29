#include "string"
#include "vector"
#include "iostream"
#include <ios>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if(i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}


/**

You are given an undirected tree with n nodes labeled 0 to n - 1. 
This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] 
indicates an undirected edge between nodes ui and vi.

You are also given a string s of length n consisting of lowercase English letters, 
where s[i] represents the character assigned to node i.

You are also given a string array queries, where each queries[i] is either:

-   "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.

-   "query ui vi": Determine whether the string formed by the characters on the 
    unique path from ui to vi (inclusive) can be rearranged into a palindrome.

Return a boolean array answer, where answer[j] is true if the jth 
query of type "query ui vi"​​​​​​​ can be rearranged into a palindrome, and false otherwise.

*/

class Tree {
public:
    int numberOfNodes;
    vector<vector<int>> adjacencyList;
    
    vector<int> parentNode;
    vector<int> distanceFromRoot;

    vector<int> subtreeStartPositionInDFS;
    vector<int> subtreeEndPositionInDFS;

    vector<int> nodesInDFSOrder;
    vector<int> subtreeSize;

    vector<vector<int>> ancestorAtPowerOfTwo;

    Tree(int numberOfNodes, const vector<vector<int>>& edges) : numberOfNodes(numberOfNodes){
        adjacencyList.resize(numberOfNodes);

        parentNode.resize(numberOfNodes);
        distanceFromRoot.resize(numberOfNodes);

        subtreeStartPositionInDFS.resize(numberOfNodes);
        subtreeEndPositionInDFS.resize(numberOfNodes);

        subtreeSize.assign(numberOfNodes, 1);

        for (const auto& edge : edges){
            int firstNode   = edge[0];
            int secondNode  = edge[1];

            adjacencyList[firstNode].push_back(secondNode);
            adjacencyList[secondNode].push_back(firstNode);
        }
        buildDFSOrderAndSubtreeRanges();
        buildAncestorTable();
    }

    void buildDFSOrderAndSubtreeRanges(){
        vector<int> dfsStack;
        dfsStack.push_back(0);
        parentNode[0] = 0;
        distanceFromRoot[0] = 0;

        while(!dfsStack.empty()){
            int currentNode = dfsStack.back();
            dfsStack.pop_back();

            subtreeStartPositionInDFS[currentNode] = nodesInDFSOrder.size();
            nodesInDFSOrder.push_back(currentNode);

            for(int neighbor : adjacencyList[currentNode]){
                if (neighbor == parentNode[currentNode]) continue;
                parentNode[neighbor] = currentNode;
                distanceFromRoot[neighbor] = distanceFromRoot[currentNode] + 1;
                dfsStack.push_back(neighbor);
            }
        }

        for(int i = (int)nodesInDFSOrder.size() - 1; i > 0; i--){
            int currentNode = nodesInDFSOrder[i];
            int parent      = parentNode[currentNode];
            subtreeSize[parent] += subtreeSize[currentNode];
        }
        for(int node = 0; node < numberOfNodes; node++){
            subtreeEndPositionInDFS[node] = subtreeStartPositionInDFS[node] + subtreeSize[node];
        }

    }

    void buildAncestorTable(){
        int numberOfAncestorLevels = 1;

        while((1LL << numberOfAncestorLevels) <= numberOfNodes){
            numberOfAncestorLevels++;
        }
        ancestorAtPowerOfTwo.assign(numberOfAncestorLevels, vector<int>(numberOfNodes));

        for(int node = 0; node < numberOfNodes; node++){
            ancestorAtPowerOfTwo[0][node] = parentNode[node];
        }
        for(int level = 1; level < numberOfAncestorLevels; level++){
            for(int node = 0; node < numberOfNodes; node++){
                int halfwayAncestor = ancestorAtPowerOfTwo[level - 1][node];
                ancestorAtPowerOfTwo[level][node] = ancestorAtPowerOfTwo[level - 1][halfwayAncestor];
            }
        }
    }
    int findLowestCommonAncestor(int firstNode, int secondNode){
        if (distanceFromRoot[firstNode] < distanceFromRoot[secondNode]) swap(firstNode, secondNode);
        int depthDifference = distanceFromRoot[firstNode] - distanceFromRoot[secondNode];
        
        for (int level = 0; depthDifference > 0; level++){
            if (depthDifference & 1){
                firstNode = ancestorAtPowerOfTwo[level][firstNode];
            }
            depthDifference >>= 1;
        }
        if (firstNode == secondNode) return firstNode;
        for(int level = (int)ancestorAtPowerOfTwo.size() - 1; level >= 0; level--){
            int firstAncestor = ancestorAtPowerOfTwo[level][firstNode];
            int secondAncestor = ancestorAtPowerOfTwo[level][secondNode];

            if (firstAncestor != secondAncestor){
                firstNode = firstAncestor;
                secondNode = secondAncestor;
            }
        }
        return parentNode[firstNode];
    }

};

class FenwickTree {
private:
    vector<int> accumulatedXor;
public:
    FenwickTree(int numberOfPositions){
        accumulatedXor.assign(numberOfPositions + 1, 0);
    }
    void updatePosition(int position, int xorValue){
        while (position < (int)accumulatedXor.size()){
            accumulatedXor[position] ^= xorValue;
            position += position & -position;
        }
    }
    int getPrefixXor(int position){
        int result = 0;
        while(position > 0){
            result ^= accumulatedXor[position];
            position -= position & -position;
        }
        return result;
    }
};

class RootPathMasks{
private:
    Tree& tree;
    vector<int> letterBitMask;
    vector<int> originalRootPathMask;
    FenwickTree subtreeChanges;
public:
    RootPathMasks(Tree& inputTree, string& letters) 
        :   tree(inputTree), 
            letterBitMask(tree.numberOfNodes), 
            originalRootPathMask(tree.numberOfNodes), 
            subtreeChanges(tree.numberOfNodes){
        for(int node = 0; node < tree.numberOfNodes; node++){
            letterBitMask[node] = 1 << (letters[node] - 'a');
        }
        for(int node : tree.nodesInDFSOrder){
            if (node == 0)  originalRootPathMask[node] = letterBitMask[node];
            else            originalRootPathMask[node] = originalRootPathMask[tree.parentNode[node]] ^ letterBitMask[node];
        }
    }
    void updateLetterAtNode(int node, char newLetter){
        int newLetterBitMask = 1 << (newLetter - 'a');
        int xorDifference    = letterBitMask[node] ^ newLetterBitMask;
        if(xorDifference == 0) return;
        int subtreeStart = tree.subtreeStartPositionInDFS[node] + 1;
        int subtreeEnd   = tree.subtreeEndPositionInDFS[node] + 1;
        subtreeChanges.updatePosition(subtreeStart, xorDifference);
        subtreeChanges.updatePosition(subtreeEnd, xorDifference);
        letterBitMask[node] = newLetterBitMask;
    }

    int getCurrentRootPathMask(int node){
        int pathMask = originalRootPathMask[node];
        int dfsPosition = tree.subtreeStartPositionInDFS[node] + 1;
        pathMask ^= subtreeChanges.getPrefixXor(dfsPosition);
        return pathMask;
    }

    bool canPathFormPalindrom(int firstNode, int secondNode){
        int commonAncestor      = tree.findLowestCommonAncestor(firstNode, secondNode);
        int firstRootPathMask   = getCurrentRootPathMask(firstNode);
        int secondRootPathMask  = getCurrentRootPathMask(secondNode); 
        int completePathMask    = firstRootPathMask ^ secondRootPathMask ^ letterBitMask[commonAncestor];
        int numberOfOddFrequencyLetters = __builtin_popcount((unsigned int) completePathMask);
        return numberOfOddFrequencyLetters <= 1;
    }


};



class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        Tree tree(n, edges);
        RootPathMasks rootPathMasks(tree, s);
        vector<bool> answers;

        for(const string& query : queries){ 
            stringstream queryParser(query);
            string operation;
            queryParser >> operation;
            if (operation == "update"){
                int  node;
                char newLetter;
                queryParser >> node >> newLetter;
                rootPathMasks.updateLetterAtNode(node, newLetter);
            }
            else if (operation == "query"){
                int firstNode;
                int secondNode;

                queryParser >> firstNode >> secondNode;
                bool canFormPalindrome = rootPathMasks.canPathFormPalindrom(firstNode, secondNode);
                answers.push_back(canFormPalindrome);
            }
        }
        return answers;
    }
};


int main(){
    Solution s;

    vector<vector<int>> edges1 = {{0,1}, {1, 2}};
    vector<vector<int>> edges2 = {{0,1}, {0, 2}, {0, 3}};

    vector<string> queries1 = {"query 0 2","update 1 b","query 0 2"};
    vector<string> queries2 = {"query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"};

    vector<bool> out1 = {true, false};
    vector<bool> out2 = {false, false, true};

    cout << "Want : " << boolalpha << out1 << ", Was : " << s.palindromePath(3, edges1, "aac", queries1) << endl;
    cout << "Want : " << boolalpha << out2 << ", Was : " << s.palindromePath(4, edges2, "abca", queries2) << endl;

    return 0;
}