import java.util.*;

class PairsProblems{
    public int CountUnique(List<Integer> listIntegers){
        return listIntegers == null ? 0 : new HashSet<Integer>(listIntegers).size();
    }
    public int CountPairs(List<Integer> listIntegers){
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for (int num : listIntegers) map.put(num, map.getOrDefault(num, 0) + 1);
        for (var key_val_pair : map.entrySet()) if (key_val_pair.getValue() == 2) ans++;
        return ans;
    }

    public int getMaxPair(List<Integer> listIntegers){
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = Integer.MIN_VALUE;
        for (int num : listIntegers) map.put(num, map.getOrDefault(num, 0) + 1);
        for (var key_val_pair : map.entrySet()) if (key_val_pair.getValue() == 2) ans = Math.max(ans, key_val_pair.getKey());
        return ans == Integer.MIN_VALUE ? -1 : ans;
    }
}

public class Pairs {
    public static void main(String[] args) {
        PairsProblems problems = new PairsProblems();

        List<Integer> nums1 = Arrays.asList(1,1,1,1,1,2,2,3,3,4,5,77,77, 9, 2,4);

        System.out.println("\nWant : 7\nWas  : " + problems.CountUnique(nums1));
        System.out.println("\nWant : 3\nWas  : " + problems.CountPairs(nums1));
        System.out.println("\nWant : 77\nWas  : " + problems.getMaxPair(nums1));

    }
}