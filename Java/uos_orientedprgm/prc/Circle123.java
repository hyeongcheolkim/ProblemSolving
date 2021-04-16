public class Circle123 {
    int x, y;
    int radius;

    public Circle123(int radius) {
        this.radius = radius;
    }

    public String toString() {
        return "Circle(r=" + radius + ")";
    }

    public boolean equals(Circle123 c1) {
        if (radius == c1.radius)
            return true;
        else
            return false;
    }

    public static void main(String[] args){
        Circle123 c1 = new Circle123(10);
        Circle123 c2 = new Circle123(20);
        System.out.println(c1);
        System.out.println(c2);

        if(c1.equals(c2))
            System.out.println("2개의 원은 같습니다.");
        else
            System.out.println("2개의 원은 다릅니다.");
    }
}

