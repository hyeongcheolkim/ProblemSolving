using System.Text;

public class Solve11651
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine()!);
        var arr = new List<(int x, int y)>();

        for (int i = 0; i < n; ++i)
        {
            var input = Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray();
            arr.Add((input[0], input[1]));
        }

        arr.Sort((a, b) =>
        {
            if (a.y == b.y)
                return a.x - b.x;
            return a.y - b.y;
        });

        var sb = new StringBuilder();
        foreach( var(x, y) in arr)
            sb.AppendLine($"{x} {y}");
        
        Console.Write(sb.ToString());
    }
}