#include "vector"
#include "iostream"
#include "algorithm"
#include <queue>

using namespace std;

/**

You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting 
will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

1.  Each meeting will take place in the unused room with the lowest number.

2.  If there are no available rooms, the meeting will be delayed until a room becomes free. 
    The delayed meeting should have the same duration as the original meeting.

3.  When a room becomes unused, meetings that have an earlier original start time should be given the room.

Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.




*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<
            pair<long long, int>, 
            vector<pair<long long, int>>, 
            greater<pair<long long, int>>> occupied;
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) available.push(i);
        for (auto& meeting : meetings){
            long long start     = meeting[0];
            long long end       = meeting[1];
            long long duration  = end - start;

            while(!occupied.empty() && occupied.top().first <= start){
                int room = occupied.top().second;
                occupied.pop();
                available.push(room);
            }
            int room;
            long long newEnd;
            if (!available.empty()){
                room = available.top();
                available.pop();
                newEnd = end;
            } else{
                auto [freeTime, freeRoom] = occupied.top();
                occupied.pop();
                room = freeRoom;
                newEnd = freeTime + duration;
            }
            count[room]++;
            occupied.push({newEnd, room});
        }
        int ans = 0;
        for (int i = 1; i < n; i++) ans = count[i] > count[ans] ? i : ans;
        return ans;      
    }
};

int main(){
    Solution s;

    vector<vector<int>> meetings1 = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    vector<vector<int>> meetings2 = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};

    cout << "\nWant : 0\nWas  : " << s.mostBooked(2, meetings1) << endl;
    cout << "\nWant : 1\nWas  : " << s.mostBooked(3, meetings2) << endl;


    return 0;
}