#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/**

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including 
previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int totalSatisfaction = 0;
        int maxLikeTime       = 0;

        for (int index = satisfaction.size() -1; index >= 0; index--){
            totalSatisfaction += satisfaction[index];
            if (totalSatisfaction <= 0) break;
            maxLikeTime += totalSatisfaction;
        }
        return maxLikeTime;
    }
};

int main(){
    Solution s;

    vector<int> satisfaction1 = {-1,-8,0,5,-9};
    vector<int> satisfaction2 = {4,3,2};
    vector<int> satisfaction3 = {-1,-4,-5};

    cout << "Want : 14, Was : " << s.maxSatisfaction(satisfaction1) << endl;
    cout << "Want : 20, Was : " << s.maxSatisfaction(satisfaction2) << endl;
    cout << "Want :  0, Was : " << s.maxSatisfaction(satisfaction3) << endl;

    return -1;
}
