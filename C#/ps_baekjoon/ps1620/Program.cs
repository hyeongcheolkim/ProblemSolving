using System;
using System.Collections.Generic;

namespace ps1620
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, m;
            String[] input = Console.ReadLine().Split(' ');
            n = Int32.Parse(input[0]);
            m = Int32.Parse(input[1]);
            Dictionary<string, string> dict1 = new Dictionary<string, string>();
            Dictionary<string, string> dict2 = new Dictionary<string, string>();
            for (int i = 1; i <= n; i++)
            {
                String name;
                name = Console.ReadLine();
                dict1.Add(name, i.ToString());
                dict2.Add(i.ToString(), name);
            }
            for (int i = 1; i <= m; i++)
            {
                String name;
                name = Console.ReadLine();
                if(dict1.ContainsKey(name))
                    Console.WriteLine(dict1[name]);
                else
                    Console.WriteLine(dict2[name]);
            }
        }
    }
}
