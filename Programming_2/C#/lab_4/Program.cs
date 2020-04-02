using System;

namespace lab_4
{
    class Program
    {
        static void Main(string[] args)
        {
            Point a = new Point(0, 0);
            Point b = new Point(0, 4);
            Point c = new Point(4, 4);
            Point d = new Point(4, 0);
            Rectangle Q1 = new Rectangle(a, b, c, d);
            //Console.WriteLine(Q1.A);
            //Console.WriteLine(Q1.Area());
            //Console.WriteLine(Q1.Perimeter());
            Console.WriteLine($"Q1:\n{Q1}");
            Console.WriteLine();
            Rectangle Q2 = Q1 / 2;
            Console.WriteLine($"Q2:\n{Q2}");
            Console.WriteLine();
            Rectangle Q3 = Q1 * 4;
            Console.WriteLine($"Q3:\n{Q3}");
            Console.WriteLine();
            Q3 -= Q2;
            Console.WriteLine($"Q3 - Q2:\n{Q3}");
            Console.WriteLine();
            Q1 += Q3;
            Console.WriteLine($"Q1 + Q3:\n{Q1}");
        }
    }
}