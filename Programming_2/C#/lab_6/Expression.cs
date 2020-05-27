using System;

namespace lab_6
{
    public class Expression
    {
        
        public Expression(double? a = null, double? b = null, double? c = null, double? d = null)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }

        public double? A { get; set; }
        public double? B { get; set; }
        public double? C { get; set; }
        public double? D { get; set; }

        public double ExpressionValue 
        {
            get
            {
                while (true)
                {
                    try
                    {
                        if (A == null)
                        {
                            Console.WriteLine("a = null! Input value: ");
                            A = Convert.ToDouble(Console.ReadLine());
                        }

                        if (B == null)
                        {
                            Console.WriteLine("b = null! Input value: ");
                            B = Convert.ToDouble(Console.ReadLine());
                        }

                        if (C == null)
                        {
                            Console.WriteLine("c = null! Input value: ");
                            C = Convert.ToDouble(Console.ReadLine());
                        }

                        if (D == null)
                        {
                            Console.WriteLine("d = null! Input value: ");
                            D = Convert.ToDouble(Console.ReadLine());
                        }
                        break;
                    }
                    catch (FormatException e)
                    {
                        Console.WriteLine(e.Message);
                        Console.WriteLine("Please re-enter. The value must be number");
                    }
                    
                }
                

                var result = Math.Log10((double) (4 * B - C)) * A / (B + C / D - 1);
                return (double) result;
            }
        }
        
        public override string ToString()
        {
            return $"ExpressionValue";
        }
    }
}