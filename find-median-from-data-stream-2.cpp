// https://leetcode.com/problems/find-median-from-data-stream/description/

typedef vector<int> vi;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        left = priority_queue<int>();
        right = priority_queue<int, vi, greater<int>>();
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        
        if (left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top() * 1.0) / 2.0; 
    }
    
private:
    priority_queue<int> left;
    priority_queue<int, vi, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
