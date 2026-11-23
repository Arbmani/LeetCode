import java.util.*;


/*

You are given a stream of points on the X-Y plane. Design an algorithm that:

-   Adds new points from the stream into a data structure. Duplicate points 
    are allowed and should be treated as different points.

-   Given a query point, counts the number of ways to choose three points from the data structure such that 
    the three points and the query point form an axis-aligned square with positive area.

An axis-aligned square is a square whose edges are all the same length 
and are either parallel or perpendicular to the x-axis and y-axis.



*/

//  Implement the DetectSquares class:
class DetectSquares {
    private Map<Integer, Map<Integer, Integer>> points;


    //  DetectSquares() Initializes the object with an empty data structure.
    public DetectSquares() {
        points = new HashMap<>();
    }
    
    //  void add(int[] point) Adds a new point point = [x, y] to the data structure.
    public void add(int[] point) {
        int x = point[0], y = point[1];
        points.putIfAbsent(x, new HashMap<>());
        Map<Integer, Integer> column = points.get(x);
        column.put(y, column.getOrDefault(y, 0) + 1);
    }
    
    //  int count(int[] point) Counts the number of ways to form axis-aligned 
    //  squares with point point = [x, y] as described above.
    public int count(int[] point) {
        int x1 = point[0], y1 = point[1], ans = 0;
        Map<Integer, Integer> column = points.getOrDefault(x1, Collections.emptyMap());
        for (int x2 : points.keySet()){
            if (x2 == x1) continue;
            int dist = x2 - x1, sameRow = points.get(x2).getOrDefault(y1, 0);
            if (sameRow == 0) continue;
            int above1 = column.getOrDefault(y1 + dist, 0);
            int above2 = points.get(x2).getOrDefault(y1 + dist, 0);
            int below1 = column.getOrDefault(y1 - dist, 0);
            int below2 = points.get(x2).getOrDefault(y1 - dist, 0);
            ans += (sameRow * above1 * above2) + (sameRow * below1 * below2); 
        }
        return ans;
    }
}




public class Detect_Squares{
    public static void main(String[] args) {
        DetectSquares ds = new DetectSquares();

        ds.add(new int[]{3, 10});
        ds.add(new int[]{11, 2});
        ds.add(new int[]{3, 2});
        System.out.println("\nWant : 1\nWas  : " + ds.count(new int[]{11, 10}));
        System.out.println("\nWant : 0\nWas  : " + ds.count(new int[]{14, 8}));
        ds.add(new int[]{11, 2});
        System.out.println("\nWant : 2\nWas  : " + ds.count(new int[]{11, 10}));
    }
}