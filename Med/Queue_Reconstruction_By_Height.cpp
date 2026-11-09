#include "vector"
#include "iostream"
#include "algorithm"

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

/**  

You are given an array of people, people, 
which are the attributes of some people in a queue (not necessarily in order). 
Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki 
other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. 
The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] 
is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] > b[0];
                return a[1] < b[1];
            });
        for (const auto& person : people) ans.insert(ans.begin() + person[1], person);
        return ans;      
    }
};

int main(){
    vector<vector<int>> people1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> people2 = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};

    vector<vector<int>> out1 = {{5,0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    vector<vector<int>> out2 = {{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}};
    Solution s;
    cout << "\nWant : " << out1 << "\nWas  : " << s.reconstructQueue(people1) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.reconstructQueue(people2) << endl;


}