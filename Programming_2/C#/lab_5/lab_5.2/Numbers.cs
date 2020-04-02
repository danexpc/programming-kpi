namespace lab_5_2
{
    public class Numbers : Rows
    { 
        public Numbers(params char[] numbers) : base(numbers)
        {}
        
        public override void Enlargement()
        {
            char[] chars = new char[Row.Length*2];
            for (int i = 0, j = 0; i < Row.Length; i++, j+=2)
            {
                chars[j] = chars[j+1] = Row[i];
            }
            Row = chars;
        }
    }
}