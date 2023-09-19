//https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150
// /146. LRU Cache


struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key),val(val),next(nullptr),prev(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> um;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(um.find(key) == um.end()) {
            return -1;
        }

        Node* node = um[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()) {
            Node* oldnode = um[key];
            remove(oldnode);
        }

        Node *node = new Node(key,value);
        um[key] = node;
        add(node);

        if(um.size() > capacity) {
            Node *delnode = head->next;
            remove(delnode);
            um.erase(delnode->key);
        }
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node* node) {
        Node * prevend = tail->prev;
        prevend->next = node;
        node->prev = prevend;
        node->next = tail;
        tail->prev = node;
    }
};