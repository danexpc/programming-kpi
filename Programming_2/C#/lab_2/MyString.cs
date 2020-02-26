using System;
using System.Collections.Generic;

namespace MyClass
{
    public class MyString
    {
        private char[] str;

        public int Lenght
        {
            get { return str.Length; }
            set
            {
                char[] temp = new char[value];
                if (value > str.Length)
                {
                    value = str.Length;
                }

                for (int i = 0; i < value; i++)
                {
                    temp[i] = str[i];
                    str = temp;
                }
            }
        }

        public char[] line
        {
            get { return str; }
        }

        public void BuildString()
        {
            string s = Console.ReadLine();
            str = new char[s.ToCharArray().Length];
            str = s.ToCharArray();
        }

        public MyString()
        {
            str = new char[256];
        }

        public MyString(int size)
        {
            str = new char[size];
        }

        public MyString(String stdStr)
        {
            str = new char[stdStr.ToCharArray().Length];
            str = stdStr.ToCharArray();
        }

        public MyString(char[] arr)
        {
            str = new char[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                str[i] = arr[i];
            }
        }

        public void RemoveSpace()
        {
            List<char> list = new List<char>();
            foreach (var c in str)
            {
                list.Add(c);
            }

            bool Space = true;
            for (int i = 0; i < list.Count; i++)
            {
                if (list[i] == 32)
                {
                    if (Space)
                    {
                        list.RemoveAt(i);
                        i--;
                    }
                    else
                        Space = true;
                }
                else
                    Space = false;
            }

            Console.WriteLine(list.Count);
            str = new char[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                str[i] = list[i];
            }
        }

        public void RemoveBeginEndSpace()
        {
            
            List<char> list = new List<char>();
            foreach (var c in str)
            {
                list.Add(c);
            }

            if (list[0] == ' ')
            {
                int i = 0;
                while (list[i] == 32)
                {
                    list.RemoveAt(i);
                }
            }
            
            if (list[list.Count-1] == ' ')
            {
                int i = list.Count-1;
                while (list[i] == 32)
                {
                    list.RemoveAt(i);
                    i--;
                }
            }
            str = new char[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                str[i] = list[i];
            }
        }
    }
}