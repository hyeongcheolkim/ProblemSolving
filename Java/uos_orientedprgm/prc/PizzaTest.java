class Pizza {
    String toppings;
    static int count = 0;

    public Pizza(String toppings) {
        this.toppings = toppings;
        count++;
    }

}

public class PizzaTest {
    public static void main(String[] args) throws Exception {
        Pizza p1 = new Pizza("Cheese");
        Pizza p2 = new Pizza("Pepperoni");
        System.out.println("피자 토핑 =" + p1.toppings);
        System.out.println("피자 토핑 =" + p2.toppings);
        System.out.println("지금까지 판매된 피자 개수 =" + Pizza.count);
        System.out.println("지금까지 판매된 피자 개수 =" + p1.count);
    }
}