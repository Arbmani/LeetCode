class SolutionreverseWords {
    public String reverseWords(String s) {
        StringBuilder   ans     = new StringBuilder();
        int             left    = 0;

        for (int right = 0; right <= s.length(); right++){
            if (right == s.length() || s.charAt(right) == ' '){
                for (int i = right - 1; i >= left; i--) ans.append(s.charAt(i));
                if (right < s.length()) ans.append(' ');
                left = right + 1;
            }
        }
        return ans.toString();
    }
}

public class Reverse_Words_in_a_String_III {
    public static void main(String[] args){
        SolutionreverseWords s = new SolutionreverseWords();

        System.out.println("\nWant : s'teL ekat edoCteeL tsetnoc\nWas  : " + s.reverseWords("Let's take LeetCode contest"));
        System.out.println("\nWant : rM gniD\nWas  : " + s.reverseWords("Mr Ding"));

    }
}