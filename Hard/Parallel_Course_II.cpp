#include "vector"
#include "iostream"
#include <queue>


using namespace std;

/**

You are given an integer n, which indicates that there are n courses labeled from 1 to n. 
You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], 
representing a prerequisite relationship between course prevCoursei and course nextCoursei: 
course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

In one semester, you can take at most k courses as long as you have taken all 
the prerequisites in the previous semesters for the courses you are taking.

Return the minimum number of semesters needed to take all courses. 
The testcases will be generated such that it is possible to take every course.

*/

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        for (auto& relation : relations){
            int prev = relation[0] - 1;
            int next = relation[1] - 1;
            prereq[next] |= (1 << prev);
        }
        int target = (1 << n) - 1;
        queue<pair<int, int>> que;
        vector<bool> visisted(1 << n, false);

        que.push({0, 0});
        visisted[0] = true;

        while (!que.empty()){
            auto [mask, semester] = que.front();
            que.pop();

            if (mask == target) return semester;
            int available = 0;
            for (int i = 0; i < n; i++){
                int bit = 1 << i;
                if (mask & bit) continue;
                if ((prereq[i] & mask) == prereq[i]) available |= bit;
            }   
            if(__builtin_popcount((unsigned)available) <= k){
                int nextMask = mask | available;
                if (!visisted[nextMask]){
                    visisted[nextMask] = true;
                    que.push({nextMask, semester + 1});
                }
            } else{
                for (int subset = available; subset; subset = (subset - 1) & available){
                    if (__builtin_popcount((unsigned int)subset) != k) continue;
                    int nextMask = mask | subset;
                    if (!visisted[nextMask]){
                        visisted[nextMask] = true;
                        que.push({nextMask, semester + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution s = Solution();

    vector<vector<int>> relations1 = {{2,1}, {3, 1}, {1, 4}};
    vector<vector<int>> relations2 = {{2,1 }, {3, 1}, {4, 1}, {1, 5}};


    cout << "\nWant : 3\nWas  : " << s.minNumberOfSemesters(4, relations1, 2) << endl;
    cout << "\nWant : 4\nWas  : " << s.minNumberOfSemesters(5, relations2, 2) << endl;



    return 0;
}


