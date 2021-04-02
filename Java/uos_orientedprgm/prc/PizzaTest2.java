class Pizza2 {
    int radius;

    Pizza2(int r) {
        radius = r;
    }

    Pizza2 Larger(Pizza2 p) {
        if(this.radius > p.radius)
            return this;
        else
            return p;
    }
}

public class PizzaTest2 {
    public static void main(String[] args) throws Exception {
        Pizza2 o1 = new Pizza2(14);
        Pizza2 o2 = new Pizza2(18);

        Pizza2 large = o1.Larger(o2);
        System.out.println(large.radius + "인치 피자가 더 큼");

    }
}
