#include "vector"
#include "iostream"
#include <queue>

using namespace std;

/**

There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(const auto& prerequisite : prerequisites){
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            adj[prereq].push_back(course); 
            indegree[course]++;
        }

        queue<int> que;
        for(int index = 0; index < numCourses; index++){
            if(indegree[index] == 0){
                que.push(index);
            }
        }
        int complete = 0;
        while(!que.empty()){
            int course = que.front();
            que.pop();
            complete++;

            for(int next : adj[course]){
                indegree[next]--;
                if(indegree[next] == 0){
                    que.push(next);
                }
            }
        }
        return complete == numCourses;
    }
};


int main(){
    Solution s;

    vector<vector<int>> prerequisites1 = {{1,0}};
    vector<vector<int>> prerequisites2 = {{1,0}, {0,1}};


    cout << "Want :  true, Was : " << boolalpha << s.canFinish(2, prerequisites1) << endl;
    cout << "Want :  false, Was : " << boolalpha << s.canFinish(2, prerequisites2) << endl;

    return 0;
}