namespace lab_4
{
    public class Point
    {
        public float X { get; set; }
        public float Y { get; set; }

        public Point():
            this(0, 0)
        {
        }
        public Point(float x, float y)
        {
            X = x;
            Y = y;
        }

        public override string ToString()
        {
            return $"{(X, Y)}";
        }
        
        public static Point operator +(Point point1, Point point2)
        {
            return new Point(point1.X + point2.X, point1.Y + point2.Y);
        }

        public static Point operator /(Point point, float num)
        {
            return new Point(point.X / num,
                            point.Y / num);
        }
        
        public static Point operator -(Point point1, Point point2)
        {
            return new Point(point1.X - point2.X, point1.Y - point2.Y);
        }
        
        public static Point operator *(Point point, float num)
        {
            return new Point(point.X * num,
                            point.Y * num);
        }
    }
}