class LRUCache {
private:
    struct Node {
            int val;
            int key;
            Node *next, *prev;
            Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
        };
    
    class DoubleLinkedList{
        Node *head, *tail;
        int size;
        public:
            DoubleLinkedList(){
                head = new Node(-1, -1);
                tail = new Node(-1, -1);

                head->next = tail;
                tail->prev = head;

                size = 0;
            }

            void removeNode(Node* node){
                // only node which is present in the linked list will
                // be removed
                Node* prev = node->prev, *next = node->next;

                prev->next = next;
                next->prev = prev;

                --size;
            }

            Node* addNode(Node* node){
                // add node to the beginning of the linked list
                Node* temp = head->next;

                head->next = node;
                node->prev = head;

                temp->prev = node;
                node->next = temp;
                
                ++size;
                return node;
            }

            Node* addNode(int key, int val){
                // add Node to the beginning of the linked list
                Node *node = new Node(key, val);
                return addNode(node);
            }

            Node* getLastNode(){
                return tail->prev;
            }

            int getSize(){
                return size;
            }
    };
    
    DoubleLinkedList dll;
    int cap;
    unordered_map<int, Node*> node_map;
    
public:
    
    LRUCache(int capacity) {
        dll = DoubleLinkedList();
        this->cap = capacity;
    }
    
    int get(int key) {
        
        if (node_map.count(key)){
            Node* node = node_map[key];
            dll.removeNode(node);
            dll.addNode(node);
            return node->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (node_map.count(key)){
            Node* node = node_map[key];
            dll.removeNode(node);
            node->val = value;
            dll.addNode(node);
            
        } else {
            if (dll.getSize() == cap){
                Node* lastNode = dll.getLastNode();
                dll.removeNode(lastNode);
                node_map.erase(lastNode->key);
                delete lastNode;
            }
            node_map[key] = dll.addNode(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
