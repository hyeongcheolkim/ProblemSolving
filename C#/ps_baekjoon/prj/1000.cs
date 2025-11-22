public class Solve1000
{
    public static void Main()
    {
        int[] input = Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray();
        var (a, b) = (input[0], input[1]);

        Console.WriteLine($"{a + b}");
    }
}