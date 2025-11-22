using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;

public class Solve12789
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine()!);
        var s = new Stack<int>();

        int target = 1;
        var arr = Console.ReadLine()!.Split(" ").Select(int.Parse).ToList();
        foreach(var x in arr)
        {
            s.Push(x);
            while(s.Count > 0 && s.Peek() == target)
            {
                ++target;
                s.Pop();
            }
        }

        if(s.Count == 0)
            Console.Write("Nice");
        else
            Console.Write("Sad");
    }
}