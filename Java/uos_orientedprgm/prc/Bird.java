class Animal {
    void walk() {
        System.out.println("걸을 수 있음.");
    }
}

public class Bird extends Animal {
    void fly() {
        System.out.println("날 수 있음.");
    }

    void sing() {
        System.out.println("노래할 수 있음");
    }
    public static void main(String[] args) throws Exception {
        Bird bird = new Bird();
        bird.walk();
        bird.fly();
        bird.sing();
    }
}
