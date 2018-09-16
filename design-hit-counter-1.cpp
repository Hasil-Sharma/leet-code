// https://leetcode.com/problems/design-hit-counter/description/

class HitCounter {
private:
    queue<int> dq;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        dq = queue<int>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        dq.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!dq.empty() && timestamp - dq.front() >= 300)
            dq.pop();
        return dq.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
