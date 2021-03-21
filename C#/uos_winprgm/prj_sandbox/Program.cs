using System;

namespace prj_sandbox
{
    class Program
    {
        static void IsOperator(object obj)
        {
            Console.WriteLine(obj + "is int:" + (obj is int));
            Console.WriteLine(obj + "is string:" + (obj is string));
        }
        static void AsOperator(object obj)
        {
            Console.WriteLine(obj + "as string ==null:" + (obj as string == null));
        }
        static void Main(string[] args)
        {
            IsOperator(10);
            IsOperator("ABC");
            AsOperator(10);
            AsOperator("ABC");
        }
    }
}
