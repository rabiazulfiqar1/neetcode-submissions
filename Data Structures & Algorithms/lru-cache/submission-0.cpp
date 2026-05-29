struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value)
        : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node* left = new Node(0, 0); // LRU
    Node* right = new Node(0, 0); // MRU
public:
    LRUCache(int capacity) {
        cap = capacity;
        left->next = right;
        right->prev = left;
    }

    void remove(Node* node) {
        Node* ptr1 = node->prev;
        Node* ptr2 = node->next;
        ptr1->next = ptr2;
        ptr2->prev = ptr1;
    }

    void insert(Node* node) {
        node->prev = right->prev;
        node->next = right;
        right->prev->next = node;
        right->prev = node;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            remove(cache[key]);
        } 
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
