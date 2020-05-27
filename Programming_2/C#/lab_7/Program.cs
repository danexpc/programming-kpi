using System;

namespace lab_7
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new LinkedList();
            list.AddLast(5);
            list.AddAfterFirst(4);
            list.AddAfterFirst(3);
            list.AddAfterFirst(2);
            Console.WriteLine(list.Count);
            var min = list.IndexMinValue;
            list.RemoveAfter(min);
        }
    }
}