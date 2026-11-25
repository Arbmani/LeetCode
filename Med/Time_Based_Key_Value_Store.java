import java.util.*;

/*

Design a time-based key-value data structure that can store multiple values for the same 
key at different time stamps and retrieve the key's value at a certain timestamp.

*/

//  Implement the TimeMap class:
class TimeMap {
    private Map<String, List<Pair>> map;

    private static class Pair {
        String  value;
        int     timestamp;
        Pair(String value, int timestamp){
            this.value      = value;
            this.timestamp  = timestamp;
        }
    }

    //  TimeMap() Initializes the object of the data structure.
    public TimeMap() {map = new HashMap<>();}
    
    //  void set(String key, String value, int timestamp) timestamps will not be dup used.
    //  Stores the key key with the value value at the given time timestamp.
    public void set(String key, String value, int timestamp) {
        map.putIfAbsent(key, new ArrayList<>());
        map.get(key).add(new Pair(value, timestamp));   // Since time is strictly increasing it will allways be sorted
    }
    
    //  String get(String key, int timestamp) Returns a value such that set was called previously, 
    //  with timestamp_prev <= timestamp. If there are multiple such values, 
    //  it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
    public String get(String key, int timestamp) {
        if (!map.containsKey(key)) return "";
        List<Pair> list = map.get(key);
        String ans = "";
        int left = 0, right = list.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            Pair pair = list.get(mid);

            if (pair.timestamp <= timestamp){
                ans  = pair.value;
                left = mid + 1;
            } else right = mid - 1;
        }
        return ans;
    }
}

public class Time_Based_Key_Value_Store{
    public static void main(String[] args) {
        TimeMap tm = new TimeMap();
        tm.set("foo", "bar", 1);
        System.out.println("\nWant : bar\nWas  : " + tm.get("foo", 1));
        System.out.println("\nWant : bar\nWas  : " + tm.get("foo", 3));
        tm.set("foo", "bar2", 4);
        System.out.println("\nWant : bar2\nWas  : " + tm.get("foo", 4));
        System.out.println("\nWant : bar2\nWas  : " + tm.get("foo", 5));
    }
}