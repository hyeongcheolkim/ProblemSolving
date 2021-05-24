using System;
using System.Linq;

namespace ps2407
{
    class Program
    {
        static long[,] memo;
        public static long combination(int a, int b)
        {

            if (a == b || b == 0)
                return 1;
            if (memo[a, b] == 0)
                return memo[a, b] = combination(a - 1, b) + combination(a - 1, b - 1);
            else
                return memo[a, b];
        }
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
            var (n, m) = (input[0], input[1]);
            memo = new long[n + 1, n + 1];
            Console.Write(combination(n, m));
        }
    }
}
