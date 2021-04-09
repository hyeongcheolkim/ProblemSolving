public class Test2 {
    public static void main(String[] args) throws Exception {
        Derived22 obj = new Derived22();
        obj.print();
    }
}

class Base2 {
    public Base2(String str) {
        System.out.println("Base()생성자" + str);
    }

    public void print() {
        System.out.println("hello");
    }
}

class Derived2 extends Base2 {
    public Derived2() {
        super("hello");
        System.out.println("Derived() 생성자");
    }
    public @Override void print(){
        System.out.println("hello2");
    }
}

class Derived22 extends Derived2 {
    public Derived22() {
        System.out.println("Derived2() 생성자");
    }

    public @Override void print() {
        super.print();
        System.out.println("hello3");
    }
}