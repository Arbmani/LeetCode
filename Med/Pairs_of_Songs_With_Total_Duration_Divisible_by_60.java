
/*

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

*/

class SolutionPairs_of_Songs_With_Total_Duration_Divisible_by_60 {
    public int numPairsDivisibleBy60(int[] time) {
        int [] remainderCount   = new int[60];
        int count               = 0;

        for (int t : time){
            int remainder   = t % 60;
            int complement  = (60 - remainder) % 60;
            count += remainderCount[complement];
            remainderCount[remainder]++;
        }

        return count;
    }
}




public class Pairs_of_Songs_With_Total_Duration_Divisible_by_60 {
    public static void main(String[] args) {
        SolutionPairs_of_Songs_With_Total_Duration_Divisible_by_60 s = new SolutionPairs_of_Songs_With_Total_Duration_Divisible_by_60();
        int[] time1 = {30,20,150,100,40};
        int[] time2 = {60,60,60};

        System.out.println("\nWant : 3\nWas  : " + s.numPairsDivisibleBy60(time1));
        System.out.println("\nWant : 3\nWas  : " + s.numPairsDivisibleBy60(time2));

    }    
}
