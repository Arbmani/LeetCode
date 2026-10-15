#include "vector"
#include "iostream"
#include "string"
#include <cstddef>
#include <functional>
#include <ostream>
#include <unordered_map>
#include <vector>
using namespace std;


/**
[Medium Problem]

Given a string expression of numbers and operators, 
return all possible results from computing all the different possible
ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer 
and the number of different results does not exceed 10^4.
*/

class Solution {
public:
    unordered_map<char, function<int(int, int)>> operations = {
        {'+', [](int x, int y){return x + y;}},
        {'-', [](int x, int y){return x - y;}},
        {'*', [](int x, int y){return x * y;}},
    };

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int index = 0; index < expression.size(); ++index){
            char op = expression[index];
            if (operations.count(op)){
                vector<int> nums1 = diffWaysToCompute(expression.substr(0, index));
                vector<int> nums2 = diffWaysToCompute(expression.substr(index + 1));
                for (int num1 : nums1){
                    for(int num2: nums2){
                        ans.push_back(operations[op](num1, num2));
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(expression));


        return ans;      
    }
};







template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    os << "[";
    for(size_t i = 0; i < vec.size(); ++i){
        if(i > 0) os << ", ";
        os << vec[i];
    }
    os << "]";
    return os;
}


int main() {
    Solution s;

    string expression1 = "2-1-1";
    string expression2 = "2*3-4*5";
    cout << "Want : " << vector<int>{0,2} << " Was : " << s.diffWaysToCompute(expression1) << endl;
    cout << "Want : " << vector<int>{-34,-14,-10,-10,10} << " Was : " << s.diffWaysToCompute(expression2) << endl;


    return -1;
}