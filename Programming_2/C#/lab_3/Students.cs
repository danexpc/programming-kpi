using System;

namespace Lab_3
{
    public class Students
    {
        
        Student[] _data;
        private int _size;
        private int _start;

        public Students(int n, int start = 0)
        {
            if (n > 0)
            {
               _data = new Student[n];
               _size = n;
               _start = start;
            }
        }

        public Student this[int index]
        {
            get { return _data[index - _start]; }
            set { _data[index - _start] = value; }
        }

        public int Size
        {
            get => _size;
        }
    }
}