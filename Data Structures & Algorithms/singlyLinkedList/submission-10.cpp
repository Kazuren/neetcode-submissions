class ListNode {
public:
    int value;
    ListNode* next = nullptr;

    ListNode(int value) : value(value), next(nullptr) {}

    ListNode(int value, ListNode* next) : value(value), next(next) {}
};

class LinkedList {
private:
    // dummy node to make operations easier by removing special cases
    ListNode* head = new ListNode(-1);
    ListNode* tail = nullptr;
public:
    LinkedList() {

    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;

        while (curr != nullptr)
        {
            if (i == index) {
                return curr->value;
            }
            curr = curr->next;
            ++i;
        }

        return -1;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = head->next;
        head->next = newHead;

        if (newHead->next == nullptr) {
            tail = newHead;
        }
    }
    
    void insertTail(int val) {
        ListNode* newTail = new ListNode(val);
        
        if (tail != nullptr)
        {
            tail->next = newTail;
        }

        if (head->next == nullptr) 
        {
            head->next = newTail;
        }

        tail = newTail;
    }

    bool remove(int index) {
        ListNode* nodeBefore = head;

        int i = 0;
        while (i < index && nodeBefore != nullptr)
        {
            ++i;
            nodeBefore = nodeBefore->next;
        }

        if (nodeBefore == nullptr || nodeBefore->next == nullptr)
        {
            return false;
        }

        ListNode* toDelete = nodeBefore->next;

        if (toDelete == tail)
        {
            tail = nodeBefore;
        }

        nodeBefore->next = nodeBefore->next->next;
        delete toDelete;
        return true;
    }

    vector<int> getValues() {
        std::vector<int> values;

        ListNode* curr = head->next;
        while (curr != nullptr)
        {
            values.push_back(curr->value);
            curr = curr->next;
        }

        return values;
    }
};
