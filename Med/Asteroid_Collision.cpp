#include "vector"
#include "iostream"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int index = 0; index < vec.size(); index++){
        os << vec[index];
        if (index + 1 < vec.size()) os << ", ";
    }
    os << "]";

    return os;
}


/**

We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, 
and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stac;
        for (int asteroid : asteroids){
            bool alive = true;
            while (alive && asteroid < 0 && !stac.empty() && stac.back() > 0){
                if      (stac.back() < -asteroid) stac.pop_back();   
                else {
                    if (stac.back()== -asteroid) stac.pop_back();
                    alive = false;
                }
            }
            if (alive) stac.push_back(asteroid);
        }
        return stac;
    }
};


int main(){
    Solution s;

    vector<int> asteroids1 = {5,10,-5};
    vector<int> asteroids2 = {8,-8};
    vector<int> asteroids3 = {10,2,-5};
    vector<int> asteroids4 = {3,5,-6,2,-1,4};

    vector<int> outs1 = {5,10};
    vector<int> outs2 = {};
    vector<int> outs3 = {10};
    vector<int> outs4 = {-6,2,4};

    cout << "\nWant : " << outs1 << "\nWas  : " << s.asteroidCollision(asteroids1) << endl;
    cout << "\nWant : " << outs2 << "\nWas  : " << s.asteroidCollision(asteroids2) << endl;
    cout << "\nWant : " << outs3 << "\nWas  : " << s.asteroidCollision(asteroids3) << endl;
    cout << "\nWant : " << outs4 << "\nWas  : " << s.asteroidCollision(asteroids4) << endl;


    return 0;
}


