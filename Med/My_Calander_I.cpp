#include "iostream"
#include <map>

using namespace std;

/**

You are implementing a program to use as your calendar. 
We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty 
intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers startTime and endTime that represents a 
booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

*/

//      Implement the MyCalendar class:
class MyCalendar {
private:
    map<int, int> calander;

public:
    //  MyCalendar() Initializes the calendar object.
    MyCalendar() {}
    
    //  boolean book(int startTime, int endTime) Returns true if the 
    //  event can be added to the calendar successfully without causing 
    //  a double booking. Otherwise, return false and do not add the event to the calendar.
    bool book(int startTime, int endTime) {
        auto next = calander.lower_bound(startTime);
        if (next != calander.end() && next->first < endTime) return false;
        if (next != calander.begin()){
            auto previous = prev(next);
            if (previous->second > startTime) return false;
        }
        calander[startTime] = endTime;
        return true;
    }
};


int main(){
    MyCalendar my;

    cout << "\n Want : true\n Was  : " <<boolalpha << my.book(10, 20) << endl;  
    cout << "\n Want : false\n Was  : " <<boolalpha << my.book(15, 25) << endl;  
    cout << "\n Want : true\n Was  : " <<boolalpha << my.book(20, 30) << endl;  

    return 0;
}


