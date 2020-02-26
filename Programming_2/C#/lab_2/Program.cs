using System;

namespace MyClass
{
    class Program
    {
        static void Main(string[] args)
        {
            MyString str1 = new MyString("bdl  aaaxf,n  hb  fg");
           
            MyString str2 = new MyString("     dsk gn    ");
           
            MyString str3 = new MyString(" kjndklsfklsdjgk lnks gldfk");
            
            Text txt = new Text(str1, str2, str3);
            txt.PrintText();
            txt.RemoveLine();
            txt.PrintText();

            Console.WriteLine(txt.ShortLine);
            Console.WriteLine(txt.PercentConsonantLetter);
            txt.RemoveSpace();
            txt.PrintText();
        }
    }
    
}