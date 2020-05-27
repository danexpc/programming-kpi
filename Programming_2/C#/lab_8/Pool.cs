using System;

namespace Lab_8
{
    public class Pool
    {
        public delegate void HandlerPool(string message);

        public event HandlerPool Notify;
        
        public Pool(double length, double width, double depth)
        {
            if (width > 0 && length > 0 && depth > 0)
            {
                _width = width;
                _depth = depth;
                _length = length;
                _volume = width * depth * length;
                _fullness = 0;
            }
            else
            {
                throw new ArgumentException("Incorrect data");
            }
        }

        private double _length;
        private double _width;
        private double _depth;
        private double _volume;
        private double _fullness;

        public double Length
        {
            get { return _length; }
            private set
            {
                _length = value;
                VolumeCalculate();
            }
        }
        public double Width
        {
            get { return _width; }
            private set
            {
                _width = value;
                VolumeCalculate();
            }
        }
        public double Depth
        {
            get { return _depth; }
            private set
            {
                _depth = value;
                VolumeCalculate();
            }
        }
        public double Volume
        {
            get => _volume;
        }
        public string Fullness
        {
            get => $"{_fullness} / {_volume}";
        }
        
        private void VolumeCalculate()
        {
            _volume = _depth * _length * _width;
        }
        
        public void ToppingUp(double number)
        {
            _fullness += number;
            
            if (_fullness >= _volume)
            {
                Notify?.Invoke($"Pool overflow");
                _fullness = _volume ;
            }
        }
        public void Draining(double number)
        {
            _fullness -= number;
            
            if (_fullness < 0)
            {
                _fullness = 0;
            }
            
        }
        
        
    }
}