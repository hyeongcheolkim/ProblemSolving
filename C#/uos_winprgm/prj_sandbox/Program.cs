using System;

namespace prj_sandbox
{
    class Program
    {
        static void Main(string[] args)
        {
            int i;
            char c;
            Console.Write("Enter a digit a character=");
            i = Console.Read() - '0';
            c = (char)Console.Read();
            Console.Write("i= " + i);
            Console.WriteLine(",c=" + c);
        }
    }
}
