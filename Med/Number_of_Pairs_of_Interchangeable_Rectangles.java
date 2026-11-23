import java.util.*;

/*

You are given n rectangles represented by a 0-indexed 2D integer array rectangles, 
where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. 
More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj 
(using decimal division, not integer division).

Return the number of pairs of interchangeable rectangles in rectangles.

*/

class SolutionNumber_of_Pairs_of_Interchangeable_Rectangles {
    private int gcd(int Anum, int Bnum){
        while (Bnum != 0){
            int temp = Bnum;
            Bnum     = Anum % Bnum;
            Anum     = temp;
        }
        return Anum;
    }


    public long interchangeableRectangles(int[][] rectangles) {
        HashMap<String, Integer> freq = new HashMap<>();
        long count = 0;

        for (int[]rectangle : rectangles){
            int width  = rectangle[0];
            int height = rectangle[1];
            int gcd_re = gcd(width, height);
            width     /= gcd_re;
            height    /= gcd_re;
            String key = width + "/" + height;
            count     += freq.getOrDefault(key, 0); 
            freq.put(key, freq.getOrDefault(key, 0) + 1);
        }
        return count;
    }
}


public class Number_of_Pairs_of_Interchangeable_Rectangles{
    public static void main(String[] args) {
        int [][] rectangles1 = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
        int [][] rectangles2 = {{4, 5}, {7, 8}};
        SolutionNumber_of_Pairs_of_Interchangeable_Rectangles s = new SolutionNumber_of_Pairs_of_Interchangeable_Rectangles();
        System.out.println("\nWant : 6\nWas  : " + s.interchangeableRectangles(rectangles1));
        System.out.println("\nWant : 0\nWas  : " + s.interchangeableRectangles(rectangles2));
    }

}