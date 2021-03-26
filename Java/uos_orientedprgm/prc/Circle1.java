public class Circle1
{
    int radius;

    void setRadius(int r) {
        radius = r;
    }

    double calcArea() {
        return 3.14 * radius * radius;
    }
    
    void print() {
        System.out.println("원의 반지름:" + radius);
        System.out.println("원의 면적:" + calcArea());
    }
    
    public static void main(String[] args) throws Exception 
    {
        Circle1 obj = new Circle1();
        obj.setRadius(100);

        obj.print();
    }
}
