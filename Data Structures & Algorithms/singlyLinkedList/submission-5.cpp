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
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    LinkedList() {

    }

    int get(int index) {
        int i = 0;
        ListNode* curr = head;
        while (curr != nullptr)
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
        if (head == nullptr) 
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
        if (tail == nullptr) {
            ListNode* newTail = new ListNode(val, nullptr);
            tail = newTail;
            head = tail;
        }
        else
        {
            ListNode* newTail = new ListNode(val, nullptr);
            tail->next = newTail;
            tail = tail->next;
        }
    }

    bool remove(int index) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int i = 0;
        while (curr != nullptr)
        {
            if (i == index) {
                if (curr == head) 
                {
                    if (head == tail) 
                    {
                        head = nullptr;
                        tail = nullptr;
                    } else
                    {
                        head = curr->next;
                    }
                } else if (curr == tail)
                {
                    prev->next = nullptr;
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
        while (curr != nullptr) {
            values.push_back(curr->value);

            curr = curr->next;
        }

        return values;
    }
};
