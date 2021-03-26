public class MyMathTest {

    public static void main(String[] args) throws Exception {
        MyMath obj = new MyMath();
        System.out.println(obj.square(10));
        System.out.println(obj.square(3.14));
    }
}

class MyMath {
    int square(int n) {
        return n * n;
    }

    double square(double n) {
        return n * n;
    }
}
