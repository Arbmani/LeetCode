class SolutionRobot_Return_to_Origin {
    public boolean judgeCircle(String moves) {
        int down = 0;
        int left = 0;
        for (int i = 0; i < moves.length(); i++){
            char cha = moves.charAt(i);
            if      (cha == 'U') down--;
            else if (cha == 'D') down++;
            else if (cha == 'L') left ++;
            else if (cha == 'R') left--;
        }
        
        return down == 0 && left == 0;
    }
}

public class Robot_Return_to_Origin{
    public static void main(String[] args){
        SolutionRobot_Return_to_Origin s = new SolutionRobot_Return_to_Origin();

        System.out.println("\nWant : true\nWas  : " + s.judgeCircle("UD"));
        System.out.println("\nWant : false\nWas  : " + s.judgeCircle("LL"));

    }
}