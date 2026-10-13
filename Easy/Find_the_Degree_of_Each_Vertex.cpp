#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> answer = {};
        for (int row = 0; row < matrix.size(); row++){
            int counter = 0;
            for(int col = 0; col < matrix[0].size(); col++){
                counter += (matrix[row][col]);
            }
            answer.push_back(counter);
        }
        return answer;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

int main() {
    Solution s;

    vector<vector<int>> matrix1 = {{0,1,1}, {1,0,1}, {1,1,0}};
    vector<vector<int>> matrix2 = {{0,1,0}, {1,0,0}, {0,0,0}};
    vector<vector<int>> matrix3 = {{0}};

    vector<int> out1 = {2, 2, 2};
    vector<int> out2 = {1, 1, 0};
    vector<int> out3 = {0};



    cout << "Want : " << out1 << ", Was : " << s.findDegrees(matrix1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.findDegrees(matrix2) << endl;
    cout << "Want : " << out3 << ", Was : " << s.findDegrees(matrix3) << endl;


}