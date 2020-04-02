using System;

namespace lab_4
{
    public class Rectangle
    {
        public Point A { private get; set; }

        public Point B { get; set; }

        public Point C { get; set; }

        public Point D { get; set; }

        public Rectangle() :
            this(new Point(0, 0),
                new Point(0, 0),
                new Point(0, 0),
                new Point(0, 0))
        {
        }
        

        public Rectangle(Point a, Point b, Point c, Point d)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        
        // Copy constructor.
        public Rectangle(Rectangle previousRectangle) :
            this(previousRectangle.A,
                previousRectangle.B,
                previousRectangle.C,
                previousRectangle.D)
        {
        }

        public static double SideLength(Point point1, Point point2)
        {
            return Math.Sqrt(Math.Pow(point1.X - point2.X, 2) + Math.Pow(point1.Y - point2.Y, 2));
        }
        public double Area()
        {
            return SideLength(A, B) * SideLength(B, C);
        }
        
        public double Perimeter()
        {
            return (SideLength(A, B) + SideLength(B, C)) * 2;
        }
        
        //public string ShowDataRectangle => $"Point:\nA{A}\tB{B}\tC{C}\tD{D}\nArea: {Area()}\tPerimeter: {Perimeter()}";
        
        public override string ToString()
        {
            return $"Point:\nA{A}  B{B}  C{C}  D{D}\nArea: {Area()}   Perimeter: {Perimeter()}";
        }

        public static Rectangle operator +(Rectangle rectangle1, Rectangle rectangle2)
        {
            return new Rectangle(rectangle1.A + rectangle2.A,
                                rectangle1.B + rectangle2.B,
                                rectangle1.C + rectangle2.C,
                                rectangle1.D + rectangle2.D);
        }
        
        public static Rectangle operator /(Rectangle rectangle, float num)
        {
            return new Rectangle(rectangle.A / num,
                                rectangle.B / num,
                                rectangle.C / num,
                                rectangle.D / num);
        }
        
        public static Rectangle operator -(Rectangle rectangle1, Rectangle rectangle2)
        {
            return new Rectangle(rectangle1.A - rectangle2.A,
                rectangle1.B - rectangle2.B,
                rectangle1.C - rectangle2.C,
                rectangle1.D - rectangle2.D);
        }
        
        public static Rectangle operator *(Rectangle rectangle, float num)
        {
            return new Rectangle(rectangle.A * num,
                rectangle.B * num,
                rectangle.C * num,
                rectangle.D * num);
        }
    }
}