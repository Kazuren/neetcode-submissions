class ListNode {
public: 
    int value;
    ListNode* next;
    ListNode(int value, ListNode* next) {
        this->value = value;
        this->next = next;
    }
};

class LinkedList {
public:
    ListNode* head = NULL;
    ListNode* tail = NULL;
    LinkedList() {

    }

    int get(int index) {
        int i = 0;
        ListNode* curr = head;
        while (curr != NULL)
        {
            if (i == index) {
                return curr->value;
            }
            ++i;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        if (head == NULL) 
        {
            ListNode* newHead = new ListNode(val, head);
            head = newHead;
            tail = head;
        } else 
        {
            ListNode* newHead = new ListNode(val, head);
            head = newHead;
        }
    }
    
    void insertTail(int val) {
        if (tail == NULL) {
            ListNode* newTail = new ListNode(val, NULL);
            tail = newTail;
            head = tail;
        }
        else
        {
            ListNode* newTail = new ListNode(val, NULL);
            tail->next = newTail;
            tail = tail->next;
        }
    }

    bool remove(int index) {
        ListNode* curr = head;
        ListNode* prev;

        int i = 0;
        while (curr != NULL)
        {
            if (i == index) {
                if (curr == head) 
                {
                    if (head == tail) 
                    {
                        head = NULL;
                        tail = NULL;
                    } else
                    {
                        head = curr->next;
                    }
                } else if (curr == tail)
                {
                    prev->next = NULL;
                    tail = prev;
                } else
                {
                    prev->next = prev->next->next;
                }
                delete curr;
                return true;
            }
            ++i;
            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    vector<int> getValues() {
        std::vector<int> values;

        ListNode* curr = head;
        while (curr != NULL) {
            values.push_back(curr->value);

            curr = curr->next;
        }

        return values;
    }
};
