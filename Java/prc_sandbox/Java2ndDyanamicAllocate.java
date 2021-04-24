import java.util.*;

public class Java2ndDyanamicAllocate {
    public static void main(String[] args) {
        List<ArrayList<Integer>> map = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < 3; i++)
            map.add(new ArrayList<Integer>(Collections.nCopies(10, 0)));
        for (int i = 0; i < map.size(); i++)
        {
            for(int j=0;j<map.get(i).size();j++)
                map.get(i).set(j, 10 * i + j);
        }
        for (int i = 0; i < map.size(); i++)
        {
            for(int j=0;j<map.get(i).size();j++)
                System.out.printf("%02d ", map.get(i).get(j));
            System.out.print('\n');
        }
    }
}
