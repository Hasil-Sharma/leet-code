// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!ump.count(key)) return -1;
        moveToFront(ump[key]);
        return ump[key]->val;
    }
    
    void put(int key, int value) {
        if (!ump.count(key) && ump.size() == capacity) removeLastNode();
        if (!ump.count(key)) ump[key] = new node(value, key);
        else ump[key]->val = value;
        moveToFront(ump[key]);
    }
    
private:
    struct node {
        int val;
        int key;
        node* next;
        node* prev;
        
        node(int v, int k) : key(k), val(v), next(NULL), prev(NULL) {}
    };
    
    node* head;
    node* tail;
    int capacity;
    unordered_map<int, node*> ump;
    
    void moveToFront(node* nd){
        connectPrevNext(nd);
        
        nd->prev = head;
        nd->next = head->next;
        head->next->prev = nd;
        head->next = nd;
    }
    
    void connectPrevNext(node* nd){
        if (nd->prev)
        nd->prev->next = nd->next;
        if (nd->next)
        nd->next->prev = nd->prev;
    }
    
    void removeLastNode(){
        if (tail->prev == head) return;
        node* nd = tail->prev;
        ump.erase(nd->key);
        connectPrevNext(nd);
        delete nd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
