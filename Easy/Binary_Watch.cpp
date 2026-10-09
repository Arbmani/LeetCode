#include <iostream>
#include <string>
#include <vector>
#include <bit>
#include <algorithm>
using namespace std;

class Solution{
public:
    /**
     * [Easy Problem] - 401. Binary Watch
     *
     * A binary watch has 4 LEDs for hours (0-11) and
     * 6 LEDs for minutes (0-59).
     *
     * Given turnedOn, return all valid times with exactly
     * turnedOn LEDs switched on.
     *
     * Hours must not have leading zeros.
     * Minutes must always contain two digits.
     *
     * @param turnedOn Number of LEDs switched on.
     * @return All valid times in "h:mm" format.
     *
     * Time complexity: O(1) - checks 12 * 60 possibilities.
     * Space complexity: O(1) auxiliary space, excluding output.
     */
    vector<string> readBinaryWatch(int turnedOn){
        vector<string> times;
        for (int h = 0; h < 12; h++){
            for (int m = 0; m < 60; m++){
                if (popcount((unsigned)h) + popcount((unsigned)m) == turnedOn)
                    times.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return times;
    }
};

/** Prints a vector of strings in array-like format. */
void printTimes(const vector<string>& times) {
    cout << "[";
    for (size_t i = 0; i < times.size(); i++)
        cout << (i ? ", " : "") << '"' << times[i] << '"';
    cout << "]";
}

int main() {
    Solution sol;

    const vector<pair<int, vector<string>>> tests = {
        {1, {"0:01", "0:02", "0:04", "0:08", "0:16",
             "0:32", "1:00", "2:00", "4:00", "8:00"}},
        {9, {}}
    };

    for (const auto& [turnedOn, expected] : tests) {
        auto actual = sol.readBinaryWatch(turnedOn);

        auto want = expected;
        sort(want.begin(), want.end());
        sort(actual.begin(), actual.end());

        cout << "turnedOn = " << turnedOn << '\n';

        cout << "Want: ";
        printTimes(want);

        cout << "\nWas:  ";
        printTimes(actual);

        cout << "\nResult: " << (want == actual ? "PASS" : "FAIL")
             << "\n\n";
    }

    return 0;
}










