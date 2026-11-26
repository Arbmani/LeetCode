
class MountainArray{
    int [] nums;
    int    counter;

    public MountainArray(int [] nums){
        this.nums = nums;
        counter   = 100;
    }

    public int get(int index){
        counter--;
        if (counter <= 0) throw new RuntimeException("To many calls to Mountian Array");
        return nums[index];
    }

    public int length(){
        counter--;
        if (counter <= 0) throw new RuntimeException("To many calls to Mountian Array");
        return nums.length;
    }
}

/*

You may recall that an array arr is a mountain array if and only if:

-   arr.length >= 3

-   There exists some i with 0 < i < arr.length - 1 such that:

    -   arr[0] < arr[1] < ... < arr[i - 1] < arr[i]

    -   arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array mountainArr, return the minimum index such 
that mountainArr.get(index) == target. If such an index does not exist, return -1.


You cannot access the mountain array directly. 
You may only access the array using a MountainArray interface:


-   MountainArray.get(k) returns the element of the array at index k (0-indexed).

-   MountainArray.length() returns the length of the array.

Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
Also, any solutions that attempt to circumvent the judge will result in disqualification

*/

class Solution {
    private int search(MountainArray arr, int target, int left, int right, boolean ascending){
        while (left <= right){
            int mid = left + (right - left) / 2;
            int val = arr.get(mid);
            if (val == target) return mid;
            if ((val < target) == ascending) left   = mid + 1;
            else                             right  = mid - 1; 
        }
        return -1;
    }


    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left  = mid + 1;
            else                                                 right = mid;
        }
        int peak = left;
        int ans  = search(mountainArr, target, 0, peak, true);
        return ans != -1 ? ans : search(mountainArr, target, peak + 1, n - 1, false);
    }
}

public class Find_in_Mountain_Array {
    public static void main(String[] args) {
        Solution s = new Solution();

        int[] nums1 = {1,2,3,4,5,3,1};
        int[] nums2 = {0,1,2,4,2,1};

        System.out.println("\nWant : 2\nWas  : " + s.findInMountainArray(3, new MountainArray(nums1)));
        System.out.println("\nWant : -1\nWas  : " + s.findInMountainArray(3, new MountainArray(nums2)));

    }
}