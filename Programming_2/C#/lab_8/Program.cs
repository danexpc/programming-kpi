using System;

namespace Lab_8
{
    class Program
    {
        static void Main(string[] args)
        {
            Pool pool = new Pool(10, 5, 2);
            pool.Notify += DisplayMessage;
            Console.WriteLine(pool.Fullness);
            pool.ToppingUp(101);
            Console.WriteLine(pool.Fullness);
        }
        private static void DisplayMessage(string message)
        {
            Console.WriteLine(message);
        }
    }
}