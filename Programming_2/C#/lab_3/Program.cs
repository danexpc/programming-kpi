using System;

namespace Lab_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Student student1 = new Student("qwer", "sdfgs", "sdffa");
            Student student2 = new Student("qwe", "sdsdgs", "hjggdfsg");
            Students table = new Students(3, 1);
            table[1] = student1;
            table[2] = student2;
            Student student3 = new Student("qweadsfg", "sdsdgsds", "hjggdfsg");
            table[3] = student3;
            Console.WriteLine(table[1]);
            Console.WriteLine(table[2]);
            Console.WriteLine(table[3]);
            Console.WriteLine(table.Size);
        }
    }
} 