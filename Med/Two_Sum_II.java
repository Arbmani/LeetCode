import java.util.*;

/*

You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.

Find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.


*/

class SolutionTwo_Sum_II {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;
        while (left < right){
            int sum = numbers[left] + numbers[right];
            if (sum == target) return new int[] {left + 1, right + 1};
            else if (sum < target) left++;
            else right--;
        }
        return new int[] {};
    }
}


public class Two_Sum_II {
    public static void main(String[] args) {
        SolutionTwo_Sum_II s = new SolutionTwo_Sum_II();
        int[] numbers1 = {2,7,11,15};
        int[] numbers2 = {2,3,4};
        int[] numbers3 = {-1,0};
        
        System.out.println("\nWant : [1, 2]\nWas  : " + Arrays.toString(s.twoSum(numbers1, 9)));
        System.out.println("\nWant : [1, 3]\nWas  : " + Arrays.toString(s.twoSum(numbers2, 6)));
        System.out.println("\nWant : [1, 2]\nWas  : " + Arrays.toString(s.twoSum(numbers3, -1)));


    }
}


