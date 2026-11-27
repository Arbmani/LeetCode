
/*

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. 
Suppose the stones have weights x and y with x <= y. The result of this smash is:

-   If x == y, both stones are destroyed, and

-   If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.


*/

class SolutionLast_Stone_Weight_II {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        int target = sum / 2;

        boolean [] dp   = new boolean[target + 1];    
        dp[0]       = true;

        for (int i = 0; i < stones.length; i++){
            int stone = stones[i];
            for (int cursum = target; cursum >= stone; cursum--){
                dp[cursum]  = dp[cursum] || dp[cursum - stone];
            }
        }
        for(int i = target; i >= 0; i--){
            if (dp[i]) return sum - 2*i;
            
        }


        return -1;
    }
}

public class Last_Stone_Weight_II{
    public static void main(String[] args) {
        SolutionLast_Stone_Weight_II s = new SolutionLast_Stone_Weight_II();

        int [] stones1 = {2,7,4,1,8,1};
        int [] stones2 = {31,26,33,21,40};


        System.out.println("\nWant : 1\nWas  : " + s.lastStoneWeightII(stones1));
        System.out.println("\nWant : 5\nWas  : " + s.lastStoneWeightII(stones2));






    }
}
