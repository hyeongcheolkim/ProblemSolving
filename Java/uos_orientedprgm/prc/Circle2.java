public class Circle2 {
    int radius;
    Point center;

    public Circle2(int radius, int x, int y) {
        this.radius = radius;
        this.center = new Point(x, y);
    }

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Line {
        int x1, y1, x2, y2;

        public Line(int a, int b, int c, int d) {
            x1 = a;
            y1 = b;
            x2 = c;
            y2 = d;
        }
    }

    double calcArea() {
        // class C {
        // String name;
        // }
        // C c = new C();
        return 3.14 * radius * radius;
    }

    public static void main(String[] args) {
        Circle2 obj = new Circle2(10, 0, 0);
        System.out.println("원의면적 = " + obj.calcArea());

        // Circle2.Point p = obj.new Point(10, 20);
        // Circle2.Line l = new Circle2.Line(10, 10, 20, 30);
    }
}
