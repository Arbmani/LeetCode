#include "vector" 
#include "string"
#include "iostream"
#include <queue>
#include <unordered_set>

/**

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a 
gene string endGene where one mutation is defined as one single character changed in the gene string.

-   For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. 
A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, 
return the minimum number of mutations needed to mutate from startGene to endGene. 
If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

*/

using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;
        unordered_set<string> validGenes(bank.begin(), bank.end());
        if (!validGenes.count(endGene)) return -1;
        const string chars = "ACGT";
        queue<pair<string, int>> que;
        que.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while (!que.empty()) {
            auto [gene, mutation] = que.front();
            que.pop();
            for(int i = 0; i < 8; i++){

                char orig = gene[i];
                for (char c: chars){
                    if (c == orig) continue;
                    gene[i] = c;
                    if (validGenes.count(gene) && !visited.count(gene)){
                        if (gene == endGene) return mutation + 1;
                        visited.insert(gene);
                        que.push({gene, mutation + 1});
                    }
                }
                gene[i] = orig;
            }
        }
        return -1;      
    }
};

int main(){
    Solution s;

    vector<string> bank1 = {"AACCGGTA"};
    vector<string> bank2 = {"AACCGGTA","AACCGCTA","AAACGGTA"};

    cout << "Want : 1, Was : " << s.minMutation("AACCGGTT", "AACCGGTA", bank1) << endl;
    cout << "Want : 2, Was : " << s.minMutation("AACCGGTT", "AAACGGTA", bank2) << endl;

    return 0;
}