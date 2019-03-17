// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        join(head, tail);
    }
    
    int get(int key) {
        if (mp.count(key)) {
            moveFront(key);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!mp.count(key) && mp.size() == cap){
            removeLast();
        }
        
        if (mp.count(key)) {
            mp[key]->val = value;
        } else {
            mp[key] = new Node(key, value);
        }
        moveFront(key);
    }
    
private:
    
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };
    
    int cap, size;
    Node *head, *tail;
    unordered_map<int, Node*> mp;
    
    void join(Node* n1, Node* n2){
        n1->next = n2;
        n2->prev = n1;
    }
    
    void moveFront(int key){
        Node* nn = mp[key], *prev = nn->prev, *next = nn->next;
        if (prev && next)
        join(prev, next);
        
        nn->next = head->next;
        head->next->prev = nn;
        
        join(head, nn);
    }
    
    void removeLast(){
        Node* nn = tail->prev;
        int k = nn->key;
        mp.erase(k);
        join(nn->prev, tail);
        delete nn;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
