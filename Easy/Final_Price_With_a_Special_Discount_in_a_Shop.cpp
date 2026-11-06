#include "vector"
#include "iostream"
#include "stack"

using namespace std;

/**

You are given an integer array prices where prices[i] 
is the price of the ith item in a shop.

There is a special discount for items in the shop. 
If you buy the ith item, then you will receive a discount equivalent to prices[j] 
where j is the minimum index such that j > i and prices[j] <= prices[i]. 
Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final 
price you will pay for the ith item of the shop, considering the special discount.


*/

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
        if ( i  + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stac;
        for (int i = 0; i < prices.size(); i++){
            while(!stac.empty() && prices[i] <= prices[stac.top()]){
                int idx = stac.top();
                stac.pop();
                prices[idx] -= prices[i];
            }
            stac.push(i);
        }
        return prices;
    }
};



int main(){
    Solution s;

    vector<int> prices1 = {8,4,6,2,3};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {10,1,1,6};

    vector<int> out1 = {4,2,4,2,3};
    vector<int> out2 = {1,2,3,4,5};
    vector<int> out3 = {9,0,1,6};

    cout <<"\nWant : " << out1 << " \nWas  : " << s.finalPrices(prices1) << endl;
    cout <<"\nWant : " << out2 << " \nWas  : " << s.finalPrices(prices2) << endl;
    cout <<"\nWant : " << out3 << " \nWas  : " << s.finalPrices(prices3) << endl;


    return 0;
}