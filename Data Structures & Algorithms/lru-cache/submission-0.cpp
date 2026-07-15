class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insertRight(Node* node) {
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            insertRight(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            removeNode(cache[key]);
        }
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertRight(newNode);
        
        if (cache.size() > capacity) {
            Node* lru = left->next;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};