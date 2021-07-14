//baekjoon ps 1759

import java.util.*;
import java.util.stream.Stream;

public class Main {

    static int L, C;
    static String[] alphabets;
    static StringBuilder res = new StringBuilder();
    static ArrayList<String> temp = new ArrayList<>();

    public static Pair count(String str) {
        char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
        int consonant = 0;
        int vowel = 0;
        for (int i = 0; i < str.length(); i++) {
            boolean flag = false;
            for (int j = 0; j < vowels.length; j++)
                if (str.charAt(i) == vowels[j])
                    flag = true;
            if (flag)
                vowel++;
            else
                consonant++;
        }
        return new Pair(consonant, vowel);
    }

    public static void dfs(int level, int idx) {
        if (level == L) {
            String str = String.join("", temp);
            Pair cnt = count(str);
            if (cnt.first >= 2 && cnt.second >= 1)
                res.append(str + '\n');
            return;
        }
        for (int i = idx; i < C; i++) {
            temp.add(alphabets[i]);
            dfs(level + 1, i + 1);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] values = Stream.of(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        alphabets = sc.nextLine().split(" ");
        Arrays.sort(alphabets);
        L = values[0];
        C = values[1];
        dfs(0, 0);
        System.out.print(res);
        sc.close();
    }
}

class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
