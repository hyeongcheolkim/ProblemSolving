using System;

namespace prj_sandbox
{
    class Program
    {
        int i;
        Program(int i)
        {
            this.i = i;
        }
        static void Swap( ref Program x, ref Program y)
        {
            Program temp = x;
            x = y;
            y = temp;
        }
        static void Main(string[] args)
        {
            Program a = new Program(1);
            Program b = new Program(2);
            Swap(ref a, ref b);
            Console.Write(a.i+"hi"+ b.i);
        }
    }
}
