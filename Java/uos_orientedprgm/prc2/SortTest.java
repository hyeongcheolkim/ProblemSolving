import java.lang.reflect.Array;
import java.util.*;

class Student implements Comparable<Student> {
    int number;
    String name;

    public Student(int number, String name) {
        this.number = number;
        this.name = name;
    }

    public String toString() {
        return name;
    }

    public int compareTo(Student s) {
        return this.number - s.number;
    }
}

public class SortTest {
    public static void main(String[] args) {
        Student arr[] = { new Student(2, "김철수"), new Student(3, "이철수"), new Student(1, "박철수"), };
        List<Student> list = Arrays.asList(arr);
        System.out.println(list);
        Collections.sort(list, (Student s1, Student s2) -> {
            return s2.number - s1.number;});
        System.out.println(list);
    }
}
