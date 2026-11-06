#include "vector"
#include "iostream"
#include "stack"
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";

    return os;
}

/**
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in 
between is shorter than both of them. More formally, the ith person can see 
the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.



*/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> stac;

        for(int i = n - 1; i >= 0; i--){
            int counter = 0;
            while(!stac.empty() && heights[i] > stac.top()){
                stac.pop();
                counter++;
            } 
            ans[i] = !stac.empty() ? counter + 1 : counter; 
            stac.push(heights[i]);
        }
        return ans;    
    }
};


int main(){
    Solution s;

    vector<int> heights1 = {10,6,8,5,11,9};
    vector<int> heights2 = {5,1,2,3,10};

    vector<int> outs1  = {3,1,2,1,1,0};
    vector<int> outs2  = {4,1,1,1,0};

    cout <<"\nWant : " << outs1 << "\nWas  : " << s.canSeePersonsCount(heights1) << endl;
    cout <<"\nWant : " << outs2 << "\nWas  : " << s.canSeePersonsCount(heights2) << endl;


    return 0;
}