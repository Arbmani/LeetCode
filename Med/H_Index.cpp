
/**
 * [Medium Problem]
 * 
    Given an array of integers citations where citations[i] is the number of citations a 
    researcher received for their ith paper, return the researcher's h-index.

    According to the definition of h-index on Wikipedia: 
    The h-index is defined as the maximum value of h such that the given 
    researcher has published at least h papers that have each been cited at least h times.

*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for(int index = 0; index < citations.size(); index++){
            if (citations[index] < index + 1) break;
            h = index + 1;
        }
        return h;
    }


    int hIndex_Ugly(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, lenLeft;
        for(int index = 0; index < citations.size(); index++){
            lenLeft = citations.size() - index;
            h       = max(h, min(citations[index], lenLeft));
            if (citations[index] > lenLeft) break;
        }

        return h;
    }
};

int main(){
    vector<int> c_1 = {3,0,6,1,5};
    vector<int> c_2 = {1,3,1};
    vector<int> c_3 = {100};
    Solution s;
    cout << "Want : 3, Was : " << s.hIndex(c_1) << endl;
    cout << "Want : 1, Was : " << s.hIndex(c_2) << endl;
    cout << "Want : 1, Was : " << s.hIndex(c_3) << endl;

    return -1;
}


