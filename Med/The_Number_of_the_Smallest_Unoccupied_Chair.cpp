#include "vector"
#include "iostream"
#include <queue>
#include <vector>
#include "algorithm"
#include "queue"

using namespace std;

/**
[Medium Problem]

There is a party where n friends numbered from 0 to n - 1 are attending. 
There is an infinite number of chairs in this party that are numbered from 0 to infinity. 
When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

-   For example, if chairs 0, 1, and 5 are occupied when a friend comes, 
    they will sit on chair number 2.

When a friend leaves the party, their chair becomes unoccupied at the moment they leave. 
If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrival_i, leaving_i], 
indicating the arrival and leaving times of the ith friend respectively, 
and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrival = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> used_chairs;
        priority_queue<int, vector<int>, greater<int>> available_chairs;
        for(int index = 0; index < times.size(); index++) available_chairs.push(index);

        for(int index = 0; index < times.size(); index ++){
            int arrival_i = times[index][0];
            int leaving_i = times[index][1];
            int chair;
            while(!used_chairs.empty() && used_chairs.top().first <= arrival_i){
                chair = used_chairs.top().second;
                used_chairs.pop();
                available_chairs.push(chair);
            }
            chair = available_chairs.top();
            available_chairs.pop();
            used_chairs.push({leaving_i, chair});
            if (arrival_i == arrival) return chair;
        }

        return -1;
    }
};

int main(){
    Solution s;

    vector<vector<int>> times1 = {{1,4}, {2,3}, {4,6}};
    vector<vector<int>> times2 = {{3,10}, {1,5}, {2,6}};

    cout << "Want : 1, Was : " << s.smallestChair(times1, 1) << endl;
    cout << "Want : 2, Was : " << s.smallestChair(times2, 0) << endl;


    return -1;
}