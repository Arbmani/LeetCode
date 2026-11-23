import java.util.*;

/*

Design an algorithm that accepts a stream of characters and checks if a suffix 
of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the 
four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm 
should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.


*/

//  Implement the StreamChecker class:

import java.util.ArrayDeque;

class StreamChecker {
    private Node        root;
    Deque<Character>    stream;
    int                 streamSize;

    private static class Node {
        Node [] childs;
        boolean isTerminal;
        Node () {
            childs      = new Node[26];
            isTerminal  = false;
        }
    }

    private void insert(String word){
        Node curr = root;
        for (char c : word.toCharArray()){
            int index = c  - 'a';
            if (curr.childs[index] == null) curr.childs[index] = new Node();
            curr = curr.childs[index];
        }
        curr.isTerminal = true;
    }

    private boolean search(){
        Node curr = root;
        for (char c : stream){
            int index = c - 'a';
            if (curr.childs[index] == null) return false;
            curr = curr.childs[index];
            if (curr.isTerminal) return true;
        }
        return false;
    }


    //  StreamChecker(String[] words) Initializes the object with the strings array words.
    public StreamChecker(String[] words) {
        this.root       = new Node();
        this.stream     = new ArrayDeque<>();
        this.streamSize = 0;
        for (String word : words){
            this.streamSize = Math.max(this.streamSize, word.length());
            word = new StringBuilder(word).reverse().toString();
            insert(word);
        }
    }
    
    //  boolean query(char letter) Accepts a new character from the stream and returns 
    //  true if any non-empty suffix from the stream forms a word that is in words.
    public boolean query(char letter) {
        if (stream.size() >= streamSize) stream.removeLast();
        stream.addFirst(letter);
        return search();        
    }
}

public class Stream_of_Characters{
    public static void main(String[] args) {
        String[] words = {"cd", "f", "kl"};
        StreamChecker sc = new StreamChecker(words);

        System.out.println("\nWant : false\nWas  : " + sc.query('a'));
        System.out.println("\nWant : false\nWas  : " + sc.query('b'));
        System.out.println("\nWant : false\nWas  : " + sc.query('c'));

        System.out.println("\nWant : true\nWas  : " + sc.query('d'));

        System.out.println("\nWant : false\nWas  : " + sc.query('e'));

        System.out.println("\nWant : true\nWas  : " + sc.query('f'));
        
        System.out.println("\nWant : false\nWas  : " + sc.query('g'));
        System.out.println("\nWant : false\nWas  : " + sc.query('h'));
        System.out.println("\nWant : false\nWas  : " + sc.query('i'));
        System.out.println("\nWant : false\nWas  : " + sc.query('j'));
        System.out.println("\nWant : false\nWas  : " + sc.query('k'));

        System.out.println("\nWant : true\nWas  : " + sc.query('l'));

    }
}