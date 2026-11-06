#include "vector"
#include "iostream"
#include "algorithm"
#include <algorithm>

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

You are given an integer n denoting the total number of servers and a 2D 
0-indexed integer array logs, where logs[i] = [server_id, time] denotes 
that the server with id server_id received a request at time time.

You are also given an integer x and a 0-indexed integer array queries.

Return a 0-indexed integer array arr of length queries.length where 
arr[i] represents the number of servers that did not receive any 
requests during the time interval [queries[i] - x, queries[i]].

Note that the time intervals are inclusive.


*/
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        vector<int> ans(queries.size(), 0);
        vector<int> freq(n + 1, 0);
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b){return a[1] < b[1];});
        for (int i = 0; i < queries.size(); i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());
        

        int left = 0, right = 0, activeServers = 0;
        for (auto [query, index] : sortedQueries){
            while (right < logs.size() && logs[right][1] <= query) {
                int id = logs[right][0];
                if  (freq[id] == 0) activeServers++;
                freq[id]++;
                right++;
            }
            while(left < right && logs[left][1] < (query - x)){
                int id = logs[left][0];
                freq[id]--;
                left++;
                if(freq[id] == 0) activeServers--;
            }
            ans[index] = n - activeServers;
        } 
        return ans;
    }
};


class Solution_Wrong {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), 
            [](const vector<int>&a, const vector<int>& b) {
                return a[1] < b[1];
            });
            vector<int> ans;
            for (int querie : queries){
                auto lowerbound = lower_bound(logs.begin(), logs.end(), querie - x,
                                    [](const vector<int>& a, int val) {
                                            return a[1] < val;
                                            });
                auto upperbound = upper_bound(logs.begin(), logs.end(), querie,
                                    [](int val, const vector<int>& a) {
                                            return val < a[1];
                                            });
                ans.push_back(n - (int)(upperbound - lowerbound));
            }
        return ans;
    }
};

int main(){
    Solution s;

    vector<vector<int>> logs1 = {{1,3}, {2,6}, {1,5}};
    vector<vector<int>> logs2 = {{2,4}, {2,1}, {1, 2}, {3, 1}};

    vector<vector<int>> logs3 = {{1,35}, {1, 32}, {1, 11}, {1, 39}, {2, 29}};

    vector<int> queries1 = {10, 11};
    vector<int> queries2 = {3, 4};

    vector<int> queries3 = {38, 30, 23, 33, 15, 31, 34, 22, 11, 14};

    cout << "\nWant : [1, 2]\nWas  : " << s.countServers(3, logs1, 5, queries1) << endl;
    cout << "\nWant : [0, 1]\nWas  : " << s.countServers(3, logs2, 2, queries2) << endl;

    cout << "\nWant : [2, 2, 3, 1, 2, 2, 1, 3, 2, 2]\nWas  : " << s.countServers(3, logs3, 8, queries3) << endl;


    return 0;
}