class Deque {

    private LinkedList<int> linkedList = new LinkedList<int>();
    public Deque() {

    }

    public bool isEmpty() {
        return linkedList.Head.Next == null;
    }

    public void append(int value) {
        linkedList.Tail.Next = new ListNode<int>(value);
        linkedList.Tail.Next.Previous = linkedList.Tail;
        linkedList.Tail = linkedList.Tail.Next;
    }

// (h) -> (1)
// (h) -> (2) -> (1)
// 
    public void appendleft(int value) {
        ListNode<int> newNode = new ListNode<int>(value);
        newNode.Next = linkedList.Head.Next;

        if (newNode.Next != null) {
            newNode.Next.Previous = newNode;
        }

        if (linkedList.Head == linkedList.Tail)
        {
            linkedList.Tail = newNode;
        }

        linkedList.Head.Next = newNode;
    }

    public int pop() {
        if (isEmpty()) {
            return -1;
        }
        int value = linkedList.Tail.Value;

        if (linkedList.Tail.Previous != null) {
            linkedList.Tail.Previous.Next = null;
            linkedList.Tail = linkedList.Tail.Previous;
        } else
        {
            linkedList.Tail = linkedList.Head;
            linkedList.Head.Next = null;
        }

        return value;
    }

    public int popleft() {
        if (isEmpty()) {
            return -1;
        }
        int value = linkedList.Head.Next.Value;
        linkedList.Head.Next = linkedList.Head.Next.Next;

        if (linkedList.Head.Next != null) {
            linkedList.Head.Next.Previous = null;
        } else
        {
            linkedList.Tail = linkedList.Head;
        }

        return value;
    }
}

public class LinkedList<T> {
    public ListNode<T> Head { get; set; }
    public ListNode<T> Tail { get; set; }

    public LinkedList() {
        Head = new ListNode<T>(default(T));
        Tail = Head;    
    }
}

public class ListNode<T> {
    public T Value { get; set; }
    public ListNode<T> Next { get; set; }
    public ListNode<T> Previous { get; set; }

    public ListNode(T value) {
        this.Value = value;
    }
}