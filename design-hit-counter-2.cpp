// https://leetcode.com/problems/design-hit-counter/description/

class HitCounter {
public:
    deque<int> dq;
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    void update(int ts){
        while(dq.size() && ts - dq.back() >= 300)
            dq.pop_back();
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        update(timestamp);
        dq.push_front(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        update(timestamp);
        return dq.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
