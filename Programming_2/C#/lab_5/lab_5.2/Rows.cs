using System;

namespace lab_5_2
{
    public class Rows
    {
        protected char[] Row { get; set; }


        public Rows(char[] row)
        {
            this.Row = row;
        }
        
        public Rows()
        {
            this.Row = null;
        }
        
        public char[] Show()
        {
            return Row;
        }

        public virtual int Len()
        {
            return Row.Length;
        }

        public virtual void Enlargement()
        {
            char[] rowAdd = Console.ReadLine()?.ToCharArray();
            if (rowAdd != null)
            {
                char[] chars = new char[Row.Length + rowAdd.Length];
                int count = 0;
                foreach (var c in Row)
                {
                    chars[count] = c;
                    count++;
                }
                foreach (var c in rowAdd)
                { 
                    chars[count] = c;
                    count++;
                }
                Row = chars;
            }
        }
        
        public override string ToString()
        {
            return new string(Row);
        }
    }
}