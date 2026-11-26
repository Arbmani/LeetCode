import java.util.*;

/*

You are given a stream of records about a particular stock. Each record contains a 
timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, 
the records do not come in order. Even worse, some records may be incorrect. 
Another record with the same timestamp may appear later in the stream 
correcting the price of the previous wrong record.

Design an algorithm that:

-   Updates the price of the stock at a particular timestamp, 
    correcting the price from any previous records at the timestamp.

-   Finds the latest price of the stock based on the current records. 
    The latest price is the price at the latest timestamp recorded.

-   Finds the maximum price the stock has been based on the current records.

-   Finds the minimum price the stock has been based on the current records.

*/

//  Implement the StockPrice class:
class StockPrice {
    private HashMap<Integer, Integer> timestampMap;
    private TreeMap<Integer, Integer> priceFreq;
    private int maxTimestamp;



    //  StockPrice() Initializes the object with no price records.
    public StockPrice() {
        timestampMap = new HashMap<>();
        priceFreq    = new TreeMap<>();
        maxTimestamp = 0;
    }
    
    //  void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
    public void update(int timestamp, int price) {
        if (timestampMap.containsKey(timestamp)){
            int oldPrice = timestampMap.get(timestamp);
            int freq     = priceFreq.get(oldPrice);

            if (freq == 1) priceFreq.remove(oldPrice);
            else           priceFreq.put(oldPrice, freq - 1);
        }

        timestampMap.put(timestamp, price);
        priceFreq.put(price, priceFreq.getOrDefault(price, 0) + 1);
        maxTimestamp = Math.max(maxTimestamp, timestamp);
    }
    
    //  int current() Returns the latest price of the stock.
    public int current() {
        return timestampMap.get(maxTimestamp);
    }
    
    //  int maximum() Returns the maximum price of the stock.
    public int maximum() {
        return priceFreq.lastKey();
    }
    
    //  int minimum() Returns the minimum price of the stock.
    public int minimum() {
        return priceFreq.firstKey();       
    }
}

public class Stock_Price_Fluctuation{
    public static void main(String[] args) {
        StockPrice sp = new StockPrice();
        sp.update(1, 10);
        sp.update(2, 5);
        System.out.println("\nWant : 5\nWas  : " + sp.current());
        System.out.println("\nWant : 10\nWas  : " + sp.maximum());
        sp.update(1, 3);
        System.out.println("\nWant : 5\nWas  : " + sp.maximum());
        sp.update(4, 2);
        System.out.println("\nWant : 2\nWas  : " + sp.minimum());

    }
}