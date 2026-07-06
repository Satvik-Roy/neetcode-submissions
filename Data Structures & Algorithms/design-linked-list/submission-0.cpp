class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* dummyHead;
    int size;

public:
    MyLinkedList() {
        dummyHead = new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* curr = dummyHead->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        
        Node* prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
    
    // Optional destructor to clean up memory when the object is destroyed
    ~MyLinkedList() {
        Node* curr = dummyHead;
        while (curr != nullptr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
};