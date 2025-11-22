public class Solve1181
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine()!);
        var s = new HashSet<string>(n);

        while (n-- != 0)
        {
            var input = Console.ReadLine()!;
            s.Add(input);
        }

        var arr = s
        .OrderBy(x => x.Length)
        .ThenBy(x => x)
        .ToList();

        Console.Write(string.Join("\n", arr));
    }
}