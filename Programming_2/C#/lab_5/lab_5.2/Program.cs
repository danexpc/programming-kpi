using System;

namespace lab_5_2
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] chars = {'a', 'k', 'c', 'k'};
            Characters characters = new Characters(chars);
            characters.Enlargement();
            Rows rows = characters;
            rows.Enlargement();
            Console.WriteLine(characters);
            Console.WriteLine(rows);
        }
    }
}