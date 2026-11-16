#include "vector"
#include "queue"
#include "iostream"

#include "unordered_set"
#include <unordered_map>


using namespace std;

/**

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

-   For example, if routes[0] = [1, 5, 7], 
    this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), 
and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++){
            for (int stop : routes[i]) stopToRoutes[stop].push_back(i);
        }
        if (!stopToRoutes.count(source) || ! stopToRoutes.count(target)) return -1;
        
        queue<int> que;
        unordered_set<int> visistedRoutes;
        unordered_set<int> visistedStops;

        que.push(source);
        visistedStops.insert(source);
        int buses = 0;
        
        while (!que.empty()){
            int size = que.size();
            buses++;
            while(size--){
                int stop = que.front();
                que.pop();

                for (int route : stopToRoutes[stop]){
                    if (visistedRoutes.count(route)) continue;
                    visistedRoutes.insert(route);
                    for (int nextStop : routes[route]){
                        if (nextStop == target) return buses;
                        if (visistedStops.insert(nextStop).second) que.push(nextStop);
                    }
                }
            }
        }




        return -1;
    }
};

int main(){
    Solution s;

    vector<vector<int>> routes1 = {{1, 2, 7}, {3, 6, 7}}; 
    vector<vector<int>> routes2 = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}}; 

    cout << "\nWant : 2\nWas  : " << s.numBusesToDestination(routes1, 1, 6) << endl;
    cout << "\nWant : -1\nWas  : " << s.numBusesToDestination(routes2, 15, 12) << endl;

    return 0;
}