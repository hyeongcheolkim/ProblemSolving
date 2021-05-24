using System;
using System.Collections.Generic;

namespace ps16953
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var a = Int64.Parse(input[0]);
            var b = Int64.Parse(input[1]);
            var q = new Queue<Tuple<long, long>>();
            q.Enqueue(new Tuple<long, long>(a, 1));
            while (q.Count != 0)
            {
                if (q.Peek().Item1 == b)
                    break;
                var temp = q.Dequeue();
                if (temp.Item1 * 10 + 1 <= b)
                    q.Enqueue(new Tuple<long, long>(temp.Item1 * 10 + 1, temp.Item2 + 1));
                if (temp.Item1 * 2 <= b)
                    q.Enqueue(new Tuple<long, long>(temp.Item1 * 2, temp.Item2 + 1));
            }
            if (q.Count == 0)
                Console.Write(-1);
            else
                Console.Write(q.Peek().Item2);
        }
    }
}
