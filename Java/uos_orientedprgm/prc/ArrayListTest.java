import java.util.*;

public class ArrayListTest 
{
    public static void main(String[] args) 
    {
        ArrayList<String> list = new ArrayList<>();
        list.add("철수");
        list.add("영희");
        list.add("순신");
        list.add("자영");
        for (String e : list)
            System.out.print(e + " ");
    }
}
