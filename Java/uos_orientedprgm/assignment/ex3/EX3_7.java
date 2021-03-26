// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_7


import java.util.*;

public class EX3_7 {
    public static void main(String[] args) {
        Random rand = new Random();
        String[] pattern = new String[] { "Clubs", "Diamonds", "Hearts", "Spades" };
        String[] num = new String[] { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
        ArrayList<String> res = new ArrayList<String>(); 

        //Math.Random사용시 5번 시행 모두 같은 결과가 나오므로 Random 클래스 사용.
        
        while (res.size() != 5) { //res사이즈가 5가 될때까지 반복.
            String temp = pattern[rand.nextInt(pattern.length)] + "의 " + num[rand.nextInt(num.length)];
            boolean flag = true; // flag가 T이면 중복 없음. F이면 중복 있음.
            for (int i = 0; i < res.size(); i++)
                if(res.get(i).equals(temp))//중복이 있으면 flag를 F로 변경.
                    flag = false;
            if(flag)//중복이 없을 경우에만 res에 결과 추가.
                res.add(temp);
        }
        
        for(int i=0;i<res.size();i++)
            System.out.println(res.get(i));
        
    }

}
