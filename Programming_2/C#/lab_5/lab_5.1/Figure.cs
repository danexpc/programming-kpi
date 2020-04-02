using System;

namespace lab_5
{
    public class Figure
    {
        protected Point[] Points;

        protected Figure(){}

        protected Figure(params Point[] points)
        {
            Points = points;
        }

        public static double SideLength(Point point1, Point point2)
        {
            return Math.Sqrt(Math.Pow(point1.X - point2.X, 2) + Math.Pow(point1.Y - point2.Y, 2));
        }
    }
}