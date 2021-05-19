//baekjoon ps 1764

import java.util.*;

public class Main {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n, m;
		String input;
		n = sc.nextInt();
		m = sc.nextInt();
		sc.nextLine();
		HashSet<String> set1 = new HashSet<String>();
		HashSet<String> set2 = new HashSet<String>();
		while (n--!=0)
		{
			input = sc.nextLine();
			set1.add(input);
		}
		while (m--!=0)
		{
			input = sc.nextLine();
			set2.add(input);
		}
		set1.retainAll(set2);
		ArrayList<String> res = new ArrayList<>(set1);
		Collections.sort(res);
		System.out.print(res.size() + "\n");
		for (int i = 0; i < res.size();i++)
			System.out.print(res.get(i) + "\n");
        sc.close();
	}
}