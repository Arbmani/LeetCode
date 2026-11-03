#include "vector"
#include "iostream"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i < vec.size() -1) os << ", ";
    }
    os << "]";

    return os;
}

/**

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to 
wait after the ith day to get a warmer temperature. 

If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n , 0);
        vector<int> monoStack;
        monoStack.reserve(n);
        for (int i = 0; i < n; i++){
            while(!monoStack.empty() && temperatures[i] > temperatures[monoStack.back()]){
                int prevIndex = monoStack.back();
                monoStack.pop_back();
                answer[prevIndex] = i - prevIndex;
            }
            monoStack.push_back(i);
        }
        return answer;        
    }
};


int main(){
    Solution s;

    vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    vector<int> temperatures2 = {30, 40, 50, 60};
    vector<int> temperatures3 = {30, 60, 90};

    vector<int> outs1 = {1,1,4,2,1,1,0,0};
    vector<int> outs2 = {1,1,1,0};
    vector<int> outs3 = {1,1,0};

    cout << "\nWant : " << outs1 << ",\nWas  : " << s.dailyTemperatures(temperatures1) << endl;
    cout << "\nWant : " << outs2 << ",\nWas  : " << s.dailyTemperatures(temperatures2) << endl;
    cout << "\nWant : " << outs3 << ",\nWas  : " << s.dailyTemperatures(temperatures3) << endl;


    return 0;
}
