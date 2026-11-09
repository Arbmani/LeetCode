#include <queue>
#include <vector>
#include <iostream>

using namespace std;

/**

You are given an array of CPU tasks, each labeled with a letter from A to Z, 
and a number n. Each CPU interval can be idle or allow the completion of one task. 
Tasks can be completed in any order, but there's a constraint: there has to be a 
gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.


*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char cha : tasks){
            freq[cha - 'A']++;
        }
        int maxFreq = 0, maxCount = 0;
        for (int fre : freq){
            if (fre > maxFreq){
                maxFreq  = fre;
                maxCount = 1;
            }
            else if(fre == maxFreq) maxCount++;
        }
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), intervals);
    }
};

int main(){
    Solution s;

    vector<char> tasks1 = {'A','A','A','B','B','B'};
    vector<char> tasks2 = {'A','C','A','B','D','B'};
    vector<char> tasks3 = {'A','A','A', 'B','B','B'};

    cout << "\nWant : 8\nWas  : " << s.leastInterval(tasks1, 2) << endl;
    cout << "\nWant : 6\nWas  : " << s.leastInterval(tasks2, 1) << endl;
    cout << "\nWant : 10\nWas  : " << s.leastInterval(tasks3, 3) << endl;


    return 0;
}