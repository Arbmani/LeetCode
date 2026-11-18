
/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

*/
class SolutiontoLowerCase {
    public String toLowerCase(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if (ch >= 'A' && ch <= 'Z') ch = (char) (ch + 32);
            ans.append(ch);
        }
        return ans.toString();
    }
}


public class To_Lower_Case{
    public static void main(String[] args){
        SolutiontoLowerCase s = new SolutiontoLowerCase();
        System.out.println("\nWant : hello\nWas  : " + s.toLowerCase("Hello"));
        System.out.println("\nWant : here\nWas  : " + s.toLowerCase("here"));
        System.out.println("\nWant : lovely\nWas  : " + s.toLowerCase("LOVELY"));
    }
}