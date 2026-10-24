#include "string"
#include "iostream"
#include "vector"
#include <cstdlib>

using namespace std;

/**
Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. 
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), 
while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). 
Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year.
 Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysBeforeMonth[] = {0, 31, 59, 90, 120, 151,181, 212, 243, 273, 304, 334};
        
        auto toDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day   = stoi(date.substr(3,2));
            return daysBeforeMonth[month - 1] + day;
        };
        int start = max(toDayOfYear(arriveAlice), toDayOfYear(arriveBob));
        int end   = min(toDayOfYear(leaveAlice), toDayOfYear(leaveBob));

        return max(0, end - start + 1);      
    }
};


int main(){
    Solution s;

    cout << "Want : 3, Was : " << s.countDaysTogether("08-15", "08-18", "08-16", "08-19") << endl;
    cout << "Want : 0, Was : " << s.countDaysTogether("10-01", "10-31", "11-01", "12-31") << endl;


    return 0;
}