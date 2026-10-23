#include "vector" 
#include "iostream" 
#include "queue" 
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v){
    os << "[";
    for (int index = 0; index < v.size(); index++){
        os << v[index];
        if(index + 1 < v.size()) os << ", ";
    }
    os << "]";

    return os;
}

/**

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> dependence(numCourses, 0);
        vector<int> ans;

        for(const auto prerequisite : prerequisites){
            int course = prerequisite[0];
            int depend = prerequisite[1];

            adj[depend].push_back(course);
            dependence[course]++;
        }
        queue<int> que;
        for(int index = 0; index < numCourses; index++){
            if (dependence[index] == 0) que.push(index);
        }

        while (!que.empty()) {
            int course = que.front();
            que.pop();
            ans.push_back(course);
            for(int next : adj[course]){
                dependence[next]--;
                if (dependence[next] == 0) que.push(next);
            }
        }
        return (ans.size() == numCourses) ? ans : vector<int> {};
    }
};


int main(){
    Solution s;

    vector<vector<int>> prerequisites1 = {{1,0}};
    vector<vector<int>> prerequisites2 = {{1,0},{2,0}, {3,1}, {3, 2}};
    vector<vector<int>> prerequisites3 = {};

    vector<int> out1 = {0,1};
    vector<int> out2 = {0,2,1,3};
    vector<int> out3 = {0};

    cout << "Want : " << out1 << ", Was : " << s.findOrder(2, prerequisites1) << endl;
    cout << "Want : " << out2 << ", Was : " << s.findOrder(4, prerequisites2) << endl;
    cout << "Want : " << out3 << ", Was : " << s.findOrder(1, prerequisites3) << endl;

    return 0;
}