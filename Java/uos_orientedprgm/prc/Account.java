public class Account {
    private String name;
    private int balance;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public static void main(String[] args) throws Exception {
        Account obj = new Account();
        obj.setName("Tom");
        obj.setBalance(100000);
        System.out.println("이름은" + obj.getName() + "통장 잔고는" + obj.getBalance() + "입니다.");
    }
}
