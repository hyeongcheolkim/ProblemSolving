using System;
using System.Collections.Generic;
using System.Linq;

namespace ps1389
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, m;
            List<KeyValuePair<int, int>> res = new List<KeyValuePair<int, int>>();
            string[] s = Console.ReadLine().Split(' ');
            n = int.Parse(s[0]);
            m = int.Parse(s[1]);
            int[,] map = new int[n + 1, n + 1];
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    map[i, j] = Int32.MaxValue/3;
            for (int i = 1; i <= n; i++)
                map[i, i] = 0;
            while (m-- != 0)
            {
                int a, b;
                s = Console.ReadLine().Split(' ');
                a = int.Parse(s[0]);
                b = int.Parse(s[1]);
                map[a, b] = map[b, a] = 1;
            }
            for (int k = 1; k <= n; k++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        map[i, j] = Math.Min(map[i, j], map[i, k] + map[k, j]);
            for (int i = 1; i <= n; i++)
            {
                int sum = 0;
                for (int j = 1; j <= n; j++)
                    sum += (map[i, j] == Int32.MaxValue ? 0 : map[i, j]);
                res.Add(new KeyValuePair<int, int>(sum, i));
            }
            res = res.OrderBy(x => x.Key).ToList();
            Console.Write(res[0].Value);
        }
    }
}
