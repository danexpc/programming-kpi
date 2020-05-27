namespace lab_7
{
    public class LinkedList
    {
        internal Node head;
        
        internal class Node {  
            internal int data;  
            internal Node next; 
            
            public Node(int d) {  
                data = d;  
                next = null;  
            }  
        }

        public void CreateNode(int value)
        {
            head = new Node(value);
        }

        public void AddLast(int value)
        {
            if (head == null)
            {
                CreateNode(value);
                return;
            }

            var current = head.next;
            
            while (current != null)
            {
                current = current.next;
            }
            
            current = new Node(value);
        }
        
        public void AddAfterFirst(int value)
        {
            if (head == null)
            {
                CreateNode(value);
                return;
            }

            if (head.next == null)
            {
                head.next = new Node(value);
                return;
            }
            
            var temp = head.next;

            head.next = new Node(value) {next = temp};
        }
        
        public int Count
        {
            get
            {
                if (head == null) return -1;

                var current = head.next;
                var counter = 0;
                
                while (current != null)
                {
                    if (current.data % 2 == 0) ++counter;
                    if (current.next == null) break;
                    current = current.next.next;
                }

                return counter;
            }
        }
        
        public int IndexMinValue
        {
            get
            {
                if (head == null) return -1;

                var current = head.next;
                var minIndex = 0;
                var minValue = head.data;
                var loopCounter = 1;

                while (current != null)
                {
                    if (minValue > current.data)
                    {
                        minIndex = loopCounter;
                        minValue = current.data;
                    }

                    ++loopCounter;
                    current = current.next;
                }

                return minIndex;
            }
        }

        public void RemoveAfter(int index)
        {
            if (head == null) return;
            
            var current = head.next;
            
            var loopCounter = 0;
            while (current != null)
            {
                loopCounter++;
                if (loopCounter == index)
                {
                    current.next = null;
                    break;
                }
                current = current.next;
            }
        }
    }
}