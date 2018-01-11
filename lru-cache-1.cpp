// https://leetcode.com/problems/lru-cache/description/
class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>:: iterator> ma;
    list<pair<int, int>> dq;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto itr = ma.find(key);
        if (itr == ma.end()) return -1;
        
        dq.splice(dq.begin(), dq, itr->second);
        return itr->second->second;
    }
    
    void put(int key, int value) {
        auto itr = ma.find(key);
        if (itr != ma.end()){
            dq.splice(dq.begin(), dq, itr->second);
            itr->second->second = value;
            return;
        }
        if (ma.size() == capacity){
            int back = dq.back().first;
            dq.pop_back();
            ma.erase(back);
        }
        dq.emplace_front(key, value);
        ma[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
