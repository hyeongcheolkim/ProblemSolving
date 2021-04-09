public class ShapeTest {
    public static void main(String[] args) throws Exception {
        Shape s;
        s = new Rectangle();
        s.x = 10;
        s.y = 20;
        // s.width = 10;

        Shape[] arrayOfShapes = new Shape[3];
        arrayOfShapes[0] = new Rectangle();
        arrayOfShapes[1] = new Triangle();
        arrayOfShapes[2] = new Circle00();

        for (int i = 0; i < arrayOfShapes.length; i++) {
            arrayOfShapes[i].draw();
            if (arrayOfShapes[i] instanceof Rectangle)
                System.out.println("Rectangle object");
            if (arrayOfShapes[i] instanceof Triangle)
                System.out.println("Triangle object");
            if (arrayOfShapes[i] instanceof Circle00)
                System.out.println("Circle00 object");
        }
        Square sq = new Square();
        sq.draw();
        Rectangle rc = sq;
        rc.draw();

    }
}

abstract class Shape {
    int x, y;

    public void move(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public abstract void draw();
}

class Rectangle extends Shape {
    int width, height;

    public void draw() {
        System.out.println("Rectangle Draw");
    }
}

class Triangle extends Shape {
    int base, height;

    public void draw() {
        System.out.println("Triangle Draw");
    }
}

class Circle00 extends Shape {
    int radius;

    public void draw() {
        System.out.println("Circle Draw");
    }
}

class Square extends Rectangle {
    public void draw() {
        System.out.println("square Draw");
    }
}
