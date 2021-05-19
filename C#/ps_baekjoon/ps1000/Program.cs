using System;

namespace ps1000
{
    class Program
    {
        static void Main(string[] args)
        {
            String[] input;
            input = Console.ReadLine().Split(" ");
            int a = Int32.Parse(input[0]);
            int b = Int32.Parse(input[1]);
            Console.Write(a + b);
        }
    }
}
