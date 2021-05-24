using System;
using System.Linq;
using System.Text;

namespace ps11660
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
            var res = new StringBuilder();
            var n = input[0];
            var m = input[1];
            var map = new int[n + 1, n + 1];
            var dp = new long[n + 1, n + 1];
            for (int i = 1; i <= n; i++)
            {
                input = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
                for (int j = 1; j <= n; j++)
                {
                    map[i, j] = input[j - 1];
                    dp[i, j] = dp[i - 1, j] + dp[i, j - 1] - dp[i - 1, j - 1] + map[i, j];
                }
            }
            for (int i = 1; i <= m; i++)
            {
                input = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
                var (x1, y1, x2, y2) = (input[0], input[1], input[2], input[3]);
                res.Append(dp[x2, y2] - dp[x2, y1 - 1] - dp[x1 - 1, y2] + dp[x1 - 1, y1 - 1]+"\n");
            }
            Console.Write(res);
        }
    }
}
