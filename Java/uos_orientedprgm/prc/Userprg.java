import java.util.*;

public class Userprg {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        User[] users = new User[5];
        while (true) {
            int select = 0;
            String userid;
            String password;
            System.out.println("===========MENU==========");
            System.out.println("1.Register new user");
            System.out.println("2.Login");
            System.out.println("3.User list");
            System.out.println("4.exit");
            System.out.println("=========================");
            select = sc.nextInt();
            sc.nextLine();
            switch (select) {
            case 1:
                System.out.print("아이디를 입력하세요:");
                userid = sc.nextLine();
                System.out.print("비밀번호를 입력하세요:");
                password = sc.nextLine();
                users[User.count] = new User(userid, password);
                break;
            case 2:
                boolean flag = false;
                System.out.print("아이디를 입력하세요:");
                userid = sc.nextLine();
                System.out.print("비밀번호를 입력하세요:");
                password = sc.nextLine();
                for (int i = 0; i < User.count; i++)
                    if (users[i].getuserid().equals(userid) && users[i].getpassword().equals(password))
                        flag = true;
                if (flag)
                    System.out.println("로그인되었습니다.");
                else
                    System.out.println("user정보가 일치하지 않습니다.");
                break;
            case 3:
                System.out.println(">>=======userlist======<<");
                for (int i = 0; i < User.count; i++)
                    System.out.println((i+1)+". "+users[i].getuserid());
                System.out.println(">>=========end=========<<");
                break;
            case 4:
                System.out.print("종료합니다.");
                sc.close();
                System.exit(0);
            default:
                System.out.println("유효하지 않은 입력입니다.");
            }
        }
    }
}

class User {
    private String userid, password;
    static int count = 0;

    public User(String userid, String password) {
        this.userid = userid;
        this.password = password;
        count++;
    }

    public String getuserid() {
        return this.userid;
    }

    public String getpassword() {
        return this.password;
    }
}
