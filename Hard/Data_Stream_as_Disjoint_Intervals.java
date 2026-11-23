import java.util.*;


/*

Given a data stream input of non-negative integers a1, a2, ..., an, 
summarize the numbers seen so far as a list of disjoint intervals.

*/

//  Implement the SummaryRanges class:
class SummaryRanges {
    private HashMap<Integer, State> map;
    private TreeMap<Integer, State> roots;

    private class State{
        int min;
        int max;
        int size;
        State parent;

        State(int value){
            this.min    = value;
            this.max    = value;
            this.size   = 1;
            this.parent = this;
        }

        State getRoot(){
            if (parent != this) parent = parent.getRoot();
            return parent;
        }

        void merge(State other){
            State a = this.getRoot();
            State b = other.getRoot();
            if (a == b) return;
            roots.remove(a.min);
            roots.remove(b.min);
            if (a.size < b.size){
                State temp = a;
                a = b;
                b = temp;
            }
            a.max = Math.max(a.max, b.max);
            a.min = Math.min(a.min, b.min);
            b.parent = a;
            a.size  += b.size;
            roots.put(a.min, a);
        }
    }


    //  SummaryRanges() Initializes the object with an empty stream.
    public SummaryRanges() {
        map   = new HashMap<>();
        roots = new TreeMap<>(); 
    }
    
    //  void addNum(int value) Adds the integer value to the stream.
    public void addNum(int value) {
        if (map.containsKey(value)) return;
        State val = new State(value);
        map.put(value, val);
        roots.put(value, val);
        if (map.containsKey(value + 1)){
            val.merge(map.get(value + 1));
        }
        if (map.containsKey(value - 1)){
            val.merge(map.get(value - 1));
        }
    }
    
    //  int[][] getIntervals() Returns a summary of the integers in the stream currently as a list 
    //  of disjoint intervals [starti, endi]. The answer should be sorted by starti.
    public int[][] getIntervals() {
        int [][] ans = new int[roots.size()][2];
        int i        = 0;
        for (State state : roots.values()){
            ans[i][0] = state.min;
            ans[i][1] = state.max;
            i++;
        }
        return ans;
    }
}


public class Data_Stream_as_Disjoint_Intervals {
    public static void main(String[] args) {
        SummaryRanges sr = new SummaryRanges();
        sr.addNum(1);
        System.out.println("\nWant : [[1, 1]]\nWas  : " + Arrays.deepToString(sr.getIntervals()));
        sr.addNum(3);
        System.out.println("\nWant : [[1, 1], [3, 3]]\nWas  : " + Arrays.deepToString(sr.getIntervals()));
        sr.addNum(7);
        System.out.println("\nWant : [[1, 1], [3, 3], [7, 7]]\nWas  : " + Arrays.deepToString(sr.getIntervals()));
        sr.addNum(2);
        System.out.println("\nWant : [[1, 3], [7, 7]]\nWas  : " + Arrays.deepToString(sr.getIntervals()));
        sr.addNum(6);
        System.out.println("\nWant : [[1, 3], [6, 7]]\nWas  : " + Arrays.deepToString(sr.getIntervals()));
    }
}