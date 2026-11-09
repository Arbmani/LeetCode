#include "vector"
#include "iostream"
#include "set"
#include <algorithm>
#include <queue>


using namespace std;

template<typename T>
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

You have k servers numbered from 0 to k-1 that are being 
used to handle multiple requests simultaneously. 
Each server has infinite computational capacity but cannot 
handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

-   The ith (0-indexed) request arrives.

-   If all servers are busy, the request is dropped (not handled at all).

-   If the (i % k)th server is available, assign the request to that server.

-   Otherwise, assign the request to the next available server 
    (wrapping around the list of servers and starting from 0 if necessary). 
    For example, if the ith server is busy, try to assign the request to the (i+1)th server, 
    then the (i+2)th server, and so on. You are given a strictly increasing array arrival of 
    positive integers, where arrival[i] represents the arrival time of the ith request, and 
    another array load, where load[i] represents the load of the ith request (the time it takes to complete). 
    Your goal is to find the busiest server(s). A server is considered busiest if it handled the most 
    number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.



*/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue< pair<int, int>,
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> busy;
        vector<int> handled(k, 0);
        set<int> available;
        for (int i = 0; i < k; i++) available.insert(i);

        for (int i = 0; i < arrival.size(); i++){
            int time = arrival[i];
            while (!busy.empty() && busy.top().first <= time){
                int server = busy.top().second;
                busy.pop();
                available.insert(server);
            }
            if (available.empty()) continue;
            int target = i % k;
            auto it = available.lower_bound(target);
            if (it == available.end()) it = available.begin();
            int server = *it;
            available.erase(it);
            handled[server]++;
            busy.push({time + load[i], server});
        }
        int maxHandled = *max_element(handled.begin(), handled.end());
        vector<int> result;
        for (int i = 0; i < k; i++){
            if (handled[i] == maxHandled) result.push_back(i);
        }


        return result;
    }
};

int main(){
    Solution s;

    vector<int> arrival1 = {1,2,3,4,5};
    vector<int> arrival2 = {1,2,3,4};
    vector<int> arrival3 = {1,2,3};

    vector<int> load1 = {5,2,3,3,3};
    vector<int> load2 = {1,2,1,2};
    vector<int> load3 = {10,12,11};

    vector<int> out1 = {1};
    vector<int> out2 = {0};
    vector<int> out3 = {0,1,2};

    cout << "\nWant : " << out1 << "\nWas  : " << s.busiestServers(3, arrival1, load1) << endl;
    cout << "\nWant : " << out2 << "\nWas  : " << s.busiestServers(3, arrival2, load2) << endl;
    cout << "\nWant : " << out3 << "\nWas  : " << s.busiestServers(3, arrival3, load3) << endl;


    return 0;
}