using System;

namespace lab_5_2
{
    public class Characters : Rows
    {
        public Characters(params char[] chars) : base(chars)
        {}
        public override void Enlargement()
        {
            int count = 0;
            foreach (var c in Row)
            {
                if (c == 'k') count++;
            }

            if (count != 0)
            {
                int newLen = Row.Length + count;
                char[] chars = new char[newLen];
                count = 0;
                foreach (var c in Row)
                {
                    chars[count] = c;
                    count++;
                    if (c == 'k')
                    {
                        chars[count] = c;
                        count++;
                    }
                }

                Row = chars;
            }
        }
    }
}