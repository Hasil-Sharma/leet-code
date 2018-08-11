// https://leetcode.com/problems/lru-cache/description/

struct node {
    int val, key;
    node *prev, *next;
    node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int cap, size;
    node *head, *tail;
    unordered_map<int, node*> nodeMap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size = 0;
        this->head = new node(-1, -1);
        this->tail = new node(-1, -1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->nodeMap = unordered_map<int, node*>();
    }
    
    int get(int key) {
        if (nodeMap.count(key)) {
            moveToFront(nodeMap[key]);
            return nodeMap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->cap == 0) return;
        if (!nodeMap.count(key) && this->size == this->cap){
            removeLastNode();
            this->size--;
        }
        if (nodeMap.count(key)) {
            nodeMap[key]->val = value;
            moveToFront(nodeMap[key]);
        } else {
            node *n = new node(key, value);
            nodeMap[key] = n;
            addToFront(n);
            this->size++;
        }
    }
    
    void addToFront(node *n){
        node *temp = head->next;
        head->next = n;
        temp->prev = n;
        n->prev = head;
        n->next = temp;
    }
    
    void moveToFront(node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
        addToFront(n);
    }
    
    void removeLastNode(){
        node *n = this->tail->prev;
        nodeMap.erase(n->key);
        n->prev->next = this->tail;
        this->tail->prev = n->prev;
        delete[] n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
