public class Complex {
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
    public static void main(String[] args){
        Complex complex = new Complex();
        complex.print();
        System.out.print('\n');
        complex.setReal(10).setImage(20).print();
    }
}