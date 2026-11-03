#include "iostream"
#include "utility"
#include "stack"

using namespace std;

/**

Design an algorithm that collects daily price quotes for some stock and returns 
the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of 
consecutive days (starting from that day and going backward) for which 
the stock price was less than or equal to the price of that day.

-   For example, if the prices of the stock in the last four days are [7,2,1,2] 
    and the price of the stock today is 2, then the span of today is 4 because 
    starting from today, the price of the stock was less than or equal to 2 for 4 consecutive days.

-   Also, if the prices of the stock in the last four days is [7,34,1,2] and the 
    price of the stock today is 8, then the span of today is 3 because starting from 
    today, the price of the stock was less than or equal 8 for 3 consecutive days.
*/


//  Implement the StockSpanner class:
class StockSpanner {
private:
    stack<pair<int, int>> monoStack;


public:
    //  StockSpanner() Initializes the object of the class.
    StockSpanner() {}
    
    //  int next(int price) Returns the span of the stock's price given that today's price is price.
    int next(int price) {
        int span = 1;
        while(!monoStack.empty() && monoStack.top().first <= price){
            span += monoStack.top().second;
            monoStack.pop();
        }
        monoStack.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 int main(){
    StockSpanner stock;
    cout << "Want : 1, Was : " << stock.next(100) << endl;
    cout << "Want : 1, Was : " << stock.next(80) << endl;
    cout << "Want : 1, Was : " << stock.next(60) << endl;
    cout << "Want : 2, Was : " << stock.next(70) << endl;
    cout << "Want : 1, Was : " << stock.next(60) << endl;
    cout << "Want : 4, Was : " << stock.next(75) << endl;
    cout << "Want : 6, Was : " << stock.next(85) << endl;


    return 0;
 }