class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp; // key → node pointer

    // Dummy head (most recent) and tail (least recent)
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);    // take out from current position
        insertFront(node);   // move to most-recent position
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists → update value and move to front
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            insertFront(node);
        } else {
            if ((int)mp.size() == capacity) {
                // Evict least recently used (just before dummy tail)
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertFront(newNode);
            mp[key] = newNode;
        }
    }
};