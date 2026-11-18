/*

You are given an m x n matrix M initialized with all 0's 
and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] 
should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.


*/


class SolutionRange_Addition_II {
    public int maxCount(int m, int n, int[][] ops) {
        if (ops.length == 0) return m * n;
        int minA = m;
        int minB = n;
        for (int [] op : ops){
            minA = Math.min(minA, op[0]);
            minB = Math.min(minB, op[1]);
        }
        return minA * minB;
    }
}


public class Range_Addition_II{
    public static void main(String[] args){
        SolutionRange_Addition_II s = new SolutionRange_Addition_II();

        int[][] ops1 = {{2, 2}, {3, 3}};
        int[][] ops2 = {{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2},{2,2}};
        int[][] ops3 = {};

        System.out.println("\nWant : 4\nWas  : " + s.maxCount(3, 3, ops1));
        System.out.println("\nWant : 4\nWas  : " + s.maxCount(3, 3, ops2));
        System.out.println("\nWant : 9\nWas  : " + s.maxCount(3, 3, ops3));
    }
}