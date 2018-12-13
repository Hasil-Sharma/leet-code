// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        for(auto n : nums){
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
