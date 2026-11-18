/*

You are given a license key represented as a string s that consists of 
only alphanumeric characters and dashes. 
The string is separated into n + 1 groups by n dashes. 
You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, 
except for the first group, which could be shorter than k but still must 
contain at least one character. Furthermore, there must be a dash inserted 
between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.


*/

class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--){
            char c = s.charAt(i);
            if (c == '-') continue;
            if (count == k){
                sb.append('-');
                count = 0;
            }
            sb.append(Character.toUpperCase(c));
            count++;
        }
        return sb.reverse().toString();       
    }
}


public class License_Key_Formatting {
    public static void main(String[] args){
        Solution s = new Solution();
        System.out.println("\nWant : 5F3Z-2E9W\nWas  : " + s.licenseKeyFormatting("5F3Z-2e-9-w", 4));
        System.out.println("\nWant : 2-5G-3J\nWas  : " + s.licenseKeyFormatting("2-5g-3-J", 2));


    }
    
}
