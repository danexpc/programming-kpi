using System;

namespace New_lab_1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int x = Convert.ToInt32(Console.ReadLine());
            int y = Convert.ToInt32(Console.ReadLine());
            int sum = 0;
            Console.WriteLine(Comparison(x, y));
            Addition(x, y, ref sum);
            Console.WriteLine(sum);
        }

        public static void Addition(int a, int b, ref int sum)
        {
            sum = a;
            while (b != 0)
            {
                sum = -~sum;
                b = ~-b;
            }
        }
        
        public static bool Comparison(int a, int b)
        {
            return (a ^ b) == 0;
        }
    }
}