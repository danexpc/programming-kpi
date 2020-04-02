using System;

namespace lab_5
{
    class Program
    {
        static void Main(string[] args)
        {
            Trapezoid trapezoid = new Trapezoid(new Point(0, 0),
                                                            new Point(1, 4),
                                                            new Point(3, 4),
                                                            new Point(4, 0));
            Console.WriteLine(trapezoid);
        }
    }
}
