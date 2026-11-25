import java.util.*;

/*

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

*/

//  Implement the FreqStack class:
class FreqStack {
    private Map<Integer, Integer> frequency;
    private Map<Integer, Stack<Integer>> group;
    private int maxFrequency;


    //  FreqStack() constructs an empty frequency stack.
    public FreqStack() {
        frequency       = new HashMap<>();
        group           = new HashMap<>();
        maxFrequency    = 0;
    }
    
    //  void push(int val) pushes an integer val onto the top of the stack.
    public void push(int val) {
        int freq = frequency.getOrDefault(val, 0) + 1;
        frequency.put(val, freq);
        maxFrequency = Math.max(maxFrequency, freq);
        group.putIfAbsent(freq, new Stack<>());
        group.get(freq).push(val);
    }
    
    //  int pop() removes and returns the most frequent element in the stack.
    //  If there is a tie for the most frequent element, 
    //  the element closest to the stack's top is removed and returned.
    public int pop() {
        Stack<Integer> stack = group.get(maxFrequency);
        int val = stack.pop();
        int freq = frequency.get(val);
        if (freq <= 1)  frequency.remove(val);
        else            frequency.put(val, freq - 1);
        if (stack.isEmpty()){
            group.remove(maxFrequency);
            maxFrequency--;
        }
        return val;
    }
}

public class Maximum_Frequency_Stack {
    public static void main(String[] args) {
        FreqStack fs = new FreqStack();
        fs.push(5);        
        fs.push(7);        
        fs.push(5);        
        fs.push(7);        
        fs.push(4);        
        fs.push(5);        
        System.out.println("\nWant : 5\nWas  : " + fs.pop());
        System.out.println("\nWant : 7\nWas  : " + fs.pop());
        System.out.println("\nWant : 5\nWas  : " + fs.pop());
        System.out.println("\nWant : 4\nWas  : " + fs.pop());

    }
}