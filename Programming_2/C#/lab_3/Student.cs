namespace Lab_3
{
    public class Student
    {
        private string _lastName;
        private string _firstName;
        private string _patronymic;

        public Student(string lastName, string firstName, string patronymic)
        {
            if (!string.IsNullOrWhiteSpace(lastName) || !string.IsNullOrWhiteSpace(lastName) || !string.IsNullOrWhiteSpace(lastName))
            {
                _lastName = lastName;
                _firstName = firstName;
                _patronymic = patronymic;
            }
        }

        public string FirstName
        {
            get => _firstName;
        }
        
        public string LastName
        {
            get => _lastName;
        }

        public string Patronymic
        {
            get => _patronymic;
        }

        public string FullName()
        {
            return _lastName + " " + _firstName + " " + _patronymic;
        }

        public override string ToString()
        {
            return FullName();
        }
    }
}