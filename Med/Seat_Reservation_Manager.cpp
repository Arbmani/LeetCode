#include "iostream"
#include "queue"
#include "vector"
#include <queue>

using namespace std;

/**

Design a system that manages the reservation state of n seats that are numbered from 1 to n.

*/

//  Implement the SeatManager class:
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> available;
    int nextSeat;

public:

    //  SeatManager(int n) Initializes a SeatManager object that will manage n 
    //  seats numbered from 1 to n. All seats are initially available.
    SeatManager(int n) {
        nextSeat = 1;
    }
    
    //  int reserve() Fetches the smallest-numbered unreserved seat, reserves 
    //  it, and returns its number.
    int reserve() {
        if (!available.empty()){
            int seat = available.top();
            available.pop();
            return seat;
        }
        return nextSeat++;
    }
    
    //  void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.
    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};

int main(){
    SeatManager sm(5);

    cout << "\nWant : 1\nWas  : " << sm.reserve() << endl;
    cout << "\nWant : 2\nWas  : " << sm.reserve() << endl;
    sm.unreserve(2);
    cout << "\nWant : 2\nWas  : " << sm.reserve() << endl;
    cout << "\nWant : 3\nWas  : " << sm.reserve() << endl;
    cout << "\nWant : 4\nWas  : " << sm.reserve() << endl;
    cout << "\nWant : 5\nWas  : " << sm.reserve() << endl;
    sm.unreserve(5);


    return -1;
}