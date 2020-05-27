using System;

namespace lab_6
{
    class Program
    {
        static void Main(string[] args)
        {
            Expression [] expressions = new Expression[10];
            expressions[0] = new Expression(-100000, 143543234, -4345232, 243532452);
            expressions[1] = new Expression(0.000000004, -0.32435422, 6.02435352, 2.342523);
            expressions[2] = new Expression(0, 0, 0, 0);
            expressions[3] = new Expression(-4, -325, -325434, -64235);
            expressions[4] = new Expression(10, 254, 62, 24.423);
            expressions[5] = new Expression(4.432, 2.343, 6.43, 2.234);
            expressions[6] = new Expression(4423, 212, 65, 2.23);
            expressions[7] = new Expression(0, 6, 23, 432.23);
            expressions[8] = new Expression(5, 00, 6, 0000);
            expressions[9] = new Expression(4, 26, 8, 0.00000);
            foreach (var expression in expressions)
            {
                Console.WriteLine(expression.ExpressionValue);
            }
        }
    }
}
