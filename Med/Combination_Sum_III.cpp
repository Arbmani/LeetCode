#include "vector"
#include "iostream"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int index = 0; index < vec.size(); index++){
        os << vec[index];
        if(index + 1 < vec.size()) os << ", ";

    }
    os << "]";

    return os;
}

/**

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

-   Only numbers 1 through 9 are used.

-   Each number is used at most once.

Return a list of all possible valid combinations. 
The list must not contain the same combination twice, and the combinations may be returned in any order.

*/

class Solution {
private:
    void backtrack(int start, int k, int remaining, vector<int>& current, vector<vector<int>>& result){
        if (current.size() == k) {
            if (remaining == 0) result.push_back(current);
            return;
        }
        for (int num = start; num <= 9; num++){
            if (num > remaining) break;
            current.push_back(num);
            backtrack(num + 1, k, remaining - num, current, result);
            current.pop_back();
        }
    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }
};


int main(){
    Solution s;
    vector<vector<int>> res1 = {{1,2,4}};
    vector<vector<int>> res2 = {{1,2,6}, {1,3,5}, {2,3,4}};
    vector<vector<int>> res3 = {};


    cout << "\nWant : " << res1 << "\nWas  : " << s.combinationSum3(3, 7) << endl;
    cout << "\nWant : " << res2 << "\nWas  : " << s.combinationSum3(3, 9) << endl;
    cout << "\nWant : " << res3 << "\nWas  : " << s.combinationSum3(4, 1) << endl;

    return 0;
}