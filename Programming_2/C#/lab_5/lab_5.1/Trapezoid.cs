using System;

namespace lab_5
{
    public class Trapezoid : Figure
    {
        public Trapezoid(params Point[] points):base(points) {}
        
        public double Area()
        {
            return (SideLength(Points[0], Points[3]) + SideLength(Points[1], Points[2])) *
                    Math.Abs(Points[1].Y - Points[0].Y) / 2;
        }
        
        public double Perimeter()
        {
            return Math.Round(SideLength(Points[0], Points[1])
                   + SideLength(Points[1], Points[2])
                   + SideLength(Points[2], Points[3]) 
                   + SideLength(Points[0], Points[3]), 3);
        }
        
        public override string ToString()
        {
            return $"Point:\nA{Points[0]}  B{Points[1]}  C{Points[2]}  D{Points[3]}\nArea: {Area()}   Perimeter: {Perimeter()}";
        }
    }
}