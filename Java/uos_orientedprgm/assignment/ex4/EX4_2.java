// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX4_2

public class EX4_2 {
    public static void main(String[] args) {
        Complex complex = new Complex();
        complex.setReal(10).setImage(20).print();
    }
}

class Complex {
    private int real;
    private int image;

    Complex() {
        real = 0;
        image = 0;
    }

    public Complex setReal(int real) {
        this.real = real;
        return this;
    }

    public Complex setImage(int image) {
        this.image = image;
        return this;
    }

    public void print() {
        System.out.printf("%d+%di", real, image);
    }
}