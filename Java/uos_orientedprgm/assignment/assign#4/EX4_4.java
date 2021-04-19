class NegativeBalanceException extends Exception {
    private int amount;

    public NegativeBalanceException(int amount) {
        this.amount = (-1) * amount;
    }

    public int get() {
        return amount;
    }
}

class BankAccount {
    private int balance;

    public BankAccount() {
        this.balance = 0;
    }

    public void depost(int amount) {
        this.balance += amount;
        System.out.println(amount + "원 입금되었습니다.");
    }

    public void withdraw(int amount) throws NegativeBalanceException {
        if (this.balance - amount >= 0) {
            this.balance -= amount;
            System.out.println(amount + "원 출금되었습니다.");
        } else
            throw new NegativeBalanceException(this.balance - amount);
    }
}

public class EX4_4 {
    public static void main(String[] args) {
        BankAccount MyAccount = new BankAccount();
        MyAccount.depost(20000);
        try {
            MyAccount.withdraw(15000);
            MyAccount.withdraw(10000);
        } catch (NegativeBalanceException err) {
            System.out.println(err.get() + "원 잔액이 부족합니다.");
        }
    }
}
