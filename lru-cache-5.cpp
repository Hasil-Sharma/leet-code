// https://leetcode.com/problems/lru-cache/description/

class LRUCache {    
private:
    struct Node {
        int label;
        Node *prev, *next;
        Node(int x) : label(x), prev(NULL), next(NULL){}
    };
    
    void moveToFront(Node* head, Node* node){
        auto prev = node->prev, next = node->next;
        join(prev, next);
        next = head->next;
        join(node, next);
        join(head, node);
    }
    
    void remove(Node* node){
        auto prev = node->prev, next = node->next;
        delete node;
        join(prev, next);
    }
    
    void join(Node* n1, Node* n2){
        if (n1) n1->next = n2;
        if (n2) n2->prev = n1;
    }
    
    Node *head, *tail;
    int capacity;
    
    unordered_map<int, Node*> mp;
    unordered_map<Node*, int> keys;
    
public:
    LRUCache(int capacity) {
        head = new Node(-1);
        tail = new Node(-1);
        join(head, tail);
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        moveToFront(head, mp[key]);
        return mp[key]->label;
    }
    
    void put(int key, int value) {

        if (capacity == 0) return;
        if (mp.size() == capacity && !mp.count(key)) {
            mp.erase(keys[tail->prev]);
            
            keys.erase(tail->prev);
            remove(tail->prev);
        }
        
        if (mp.count(key)) mp[key]->label = value;
        else mp[key] = new Node(value);
        
        keys[mp[key]] = key;
        moveToFront(head, mp[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
