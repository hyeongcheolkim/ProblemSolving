import java.util.*;

public class InputSting 
{
    public static void main(String[] args) throws Exception 
    {
        String name;
        int age;

        Scanner sc = new Scanner(System.in);
        System.out.print("이름을 입력하시오:");
        name = sc.nextLine();

        System.out.print("나이를 입력하시오:");
        age = sc.nextInt();
        System.out.println(name + "님 안녕하세요" + age + "살이시네요.");
        sc.close();

    }
    
}
