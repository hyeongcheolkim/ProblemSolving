public class Complexnum {
    public static void main(String[] args) throws Exception {
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

    Complex setReal(int real) {
        this.real = real;
        return this;
    }

    Complex setImage(int image) {
        this.image = image;
        return this;
    }

    void print() {
        System.out.printf("%d+%di", real, image);
    }
}
