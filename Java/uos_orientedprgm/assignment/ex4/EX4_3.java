// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX4_3

public class EX4_3 {
    public static void main(String args[]) {
        Account a1 = new Account("철수");
        a1.deposit(50000);
        Account a2 = new Account("영희");
        a2.deposit(100000);
        a1.withdraw();
        a2.withdraw();
        a1.transfer(50000, a2);
        a1.withdraw();
        a2.withdraw();
    }
}

class Account {
    private String name;
    private int balance;
    
    public Account(){
        this.name = "";
        this.balance = 0;
        System.out.println("새로운 무명계좌가 생성되었습니다. 잔액은 0원입니다.");
    }
    public Account(String name){
        this.name = name;
        this.balance = 0;
        System.out.println("새로운 " + name + " 계좌가 생성되었습니다. 잔액은 0원입니다.");
    }
    public Account(String name, int balance){
        this.name = name;
        this.balance = balance;
        System.out.println("새로운 " + name + " 계좌가 생성되었습니다. 잔액은 "+balance+"원입니다.");
    }
    
    public String getname() {
        return name;
    }

    public void withdraw() {
        System.out.println(this.name+"고객 계좌잔고 = "+balance+"원");
    }

    public void deposit(int amount) {
        this.balance += amount;
        System.out.println(this.name + "계좌에 " + amount + "원 저축하였습니다.");
    }

    public void transfer(int amount, Account account){
        this.balance -= amount;
        account.deposit(amount);
        System.out.println(this.name+"가 "+account.getname()+"에게 "+amount+"원 이체함.");
    }
}

