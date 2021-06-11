import java.util.*;
import java.util.Random;

class RandomList<T> {
    private ArrayList<T> list;
    Random random;
    RandomList() {
        list = new ArrayList<T>();
        random = new Random();
    }
    RandomList(int capacity) {
        list = new ArrayList<T>(capacity);
        random = new Random();
    }

    public void add(T num) {
        list.add(num);
    }

    public int size() {
        return list.size();
    }

    public T get(int num) {
        return list.get(num);
    }

    public T select() {
        return list.get(random.nextInt(list.size()));
    }

}

public class EX6_3 {
    public static void main(String[] args) {
        RandomList<Integer> rla = new RandomList<Integer>(2);
        rla.add(10);
        rla.add(20);
        rla.add(50);
        for (int i = 0; i < rla.size(); i++) {
            System.out.println(rla.get(i));
            System.out.println(rla.select());
        }
        RandomList<String> rlb = new RandomList<String>(1);
        rlb.add("We");
        rlb.add("Are");
        rlb.add("The");
        rlb.add("World");
        for (int i = 0; i < rlb.size(); i++) {
            System.out.println(rlb.get(i));
            System.out.println(rlb.select());
        }
    }
}