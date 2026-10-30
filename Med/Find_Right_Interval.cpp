#include "vector" 
#include "iostream" 
#include "algorithm" 
#include <algorithm>

using namespace std;
template <typename T>
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

You are given an array of intervals,
where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j 
such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.


*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> starts;
        for(int i = 0; i < n; i++) starts.push_back({intervals[i][0], i});
        sort(starts.begin(), starts.end());
        vector<int> ans(n, -1);

        for(int index = 0; index < n; index++){
            int end = intervals[index][1];
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(end, -1));
            if (it != starts.end()) ans[index] = it->second;
        }
        return ans;      
    }
};

int main(){
    Solution s;

    vector<vector<int>> intervals1 = {{1,2}};
    vector<vector<int>> intervals2 = {{3,4}, {2,3}, {1,2}};
    vector<vector<int>> intervals3 = {{1,4}, {2,3}, {3,4}};

    vector<int> out1 = {-1};
    vector<int> out2 = {-1,0,1};
    vector<int> out3 = {-1, 2, -1};
    
    cout << "\nWant : " << out1 << "\nWas :  " << s.findRightInterval(intervals1) << endl;
    cout << "\nWant : " << out2 << "\nWas :  " << s.findRightInterval(intervals2) << endl;
    cout << "\nWant : " << out3 << "\nWas :  " << s.findRightInterval(intervals3) << endl;

    return 0;
}