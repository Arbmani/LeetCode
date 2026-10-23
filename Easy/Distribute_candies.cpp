#include "vector"
#include "iostream"
#include <unordered_set>
#include <algorithm>

using namespace std;

/**

Alice has n candies, where the ith candy is of type candyType[i]. 
Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). 
Alice likes her candies very much, and she wants to eat the maximum 
number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, 
return the maximum number of different types of candies she can eat if she only eats n / 2 of them.


*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueCandy(candyType.begin(), candyType.end());
        return min(uniqueCandy.size(), candyType.size() / 2);
    }
};

int main(){
    Solution s;

    vector<int> candyType1 = {1,1,2,2,3,3};
    vector<int> candyType2 = {1,1,2,3};
    vector<int> candyType3 = {6,6,6,6};

    cout << "Want : 3, Was : " << s.distributeCandies(candyType1) << endl;
    cout << "Want : 2, Was : " << s.distributeCandies(candyType2) << endl;
    cout << "Want : 1, Was : " << s.distributeCandies(candyType3) << endl;

    return 0;
}

