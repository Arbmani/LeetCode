/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.


*/


class SolutionvalidPalindrome {
    private boolean isPalindrome(String s, int left, int right){
        while (left < right){
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }


    public boolean validPalindrome(String s) {
        int left    = 0;
        int right   = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)){
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
    
        return true;
    }
}

public class Valid_Palindrome_II{
    public static void main(String[] args){
        SolutionvalidPalindrome s = new SolutionvalidPalindrome();
        System.out.println("\nWant : true\nWas  : " + s.validPalindrome("aba"));
        System.out.println("\nWant : true\nWas  : " + s.validPalindrome("abca"));
        System.out.println("\nWant : false\nWas  : " + s.validPalindrome("abc"));

    }
}