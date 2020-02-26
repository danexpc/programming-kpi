using System;
using System.Collections.Generic;

namespace MyClass
{
    public class Text
    {
        List<MyString> text;
        
        public Text()
        {
            text = new List<MyString>();
        }

        public Text(params MyString[] str)
        {
            text = new List<MyString>();
            foreach (var line in str)
            {
                text.Add(line);
            }
        }
        
        public void AddLine(MyString str)
        {
            text.Add(str);
        }

        public void RemoveLine()
        {
            text.RemoveAt(text.Count - 1);
        }
        
        public void Remove_Line(int index)
        {
            text.RemoveAt(index);
        }

        public void PrintText()
        {
            foreach (var str in text)
            {
                Console.WriteLine(str.line);
            }
        }
        
        public void Clear()
        {
            text.Clear();
        }

        public int ShortLine
        {
            get
            {
                int min_line = text[0].Lenght;
                for (int i = 1; i < text.Count; i++)
                {
                    if (text[i].Lenght < min_line)
                    {
                        min_line = text[i].Lenght;
                    }
                }

                return min_line;
            }
        }

        public double PercentConsonantLetter
        {
            get
            {
                List<char> consonant = new List<char>{'a', 'e', 'i', 'o', 'u', 'y'};
                double allLetter = 0;
                double consonantLetter = 0;

                foreach (var line in text)
                {
                    foreach (var c in line.line)
                    {
                        if (Char.IsLetter(c))
                        {
                            allLetter++;
                            if (!consonant.Contains(char.ToLower(c)))
                            {
                                consonantLetter++;
                            }
                        }
                    }
                }
                double percent = (consonantLetter / allLetter) * 100;
                return Math.Round(percent, 2);
            }
        }

        public void RemoveSpace()
        {
            foreach (var line in text)
            {
                line.RemoveSpace();
            }
        }

        public void RemoveBeginEndSpace()
        {
            foreach (var line in text)
            {
                line.RemoveBeginEndSpace();
            }
        }
    }
}