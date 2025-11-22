public class Solve25305
{
    public static void Main()
    {
        var (n, k) = Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray() switch { var x => (x[0], x[1]) };
        var li = Console.ReadLine()!.Split(" ").Select(int.Parse).Take(n).ToList();
        li.Sort((a, b) => b - a);
        Console.Write(li[k - 1]);
    }
}