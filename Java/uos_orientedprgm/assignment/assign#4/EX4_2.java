class Rectangle {
    int width, height;

    public Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    public void print() {
        System.out.println("가로:" + width);
        System.out.println("세로:" + height);
    }
}

class ColorRectangle extends Rectangle {
    String color;

    public ColorRectangle(int w, int h, String color) {
        super(w, h);
        this.color = color;
    }

    public void print() {
        System.out.println("가로:" + width);
        System.out.println("세로:" + height);
        System.out.println("색상:" + color);
    }
}

public class EX4_2 {
    static public void main(String[] args) {
        ColorRectangle cr = new ColorRectangle(100, 100, "blue");
        cr.print();
    }
}