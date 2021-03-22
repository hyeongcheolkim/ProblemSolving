class Circle {
    int radius;
    String color;

    double calcArea() {
        return 3.14 * radius * radius;
    }
}

public class CircleTest {
    public static void main(String[] args) throws Exception {
        Circle obj = new Circle();
        obj.radius = 100;
        obj.color = "blue";
        double area = obj.calcArea();
        System.out.println("원의 면적=" + area);
    }
}
