import java.util.*;

/*

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, 
it is the product of some integer with itself. For example, 1, 4, 9, 
and 16 are perfect squares while 3 and 11 are not.

*/

class SolutionPerfect_Square {
    public int numSquares(int n) {
        ArrayList<Integer> perfectSquares = new ArrayList<>();
        for (int i = 1; i <= n / i; i++) perfectSquares.add(i * i);
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0]    = 0;

        for (int i = 0; i < perfectSquares.size(); i++){
            int square = perfectSquares.get(i);
            for(int sum = square; sum <= n; sum++){
                dp[sum] = Math.min(dp[sum], dp[sum - square] + 1);
            }
        }

        return dp[n];          
    }
}

public class Perfect_Square{
    public static void main(String[] args) {
        SolutionPerfect_Square s = new SolutionPerfect_Square();
        System.out.println("\nWant : 3\nWas  : " + s.numSquares(12));
        System.out.println("\nWant : 2\nWas  : " + s.numSquares(13));

    }
}