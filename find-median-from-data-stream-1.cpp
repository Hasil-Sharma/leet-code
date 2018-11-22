// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        first = priority_queue<long>();
        second = priority_queue<long, vector<long>, greater<long>>();
    }
    
    void addNum(int num) {
        first.push(num);
        second.push(first.top());
        first.pop();
        if (first.size() < second.size()){
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        return first.size() > second.size() ? first.top() : (first.top() + second.top())/2.0;
    }
    
private:
    priority_queue<long> first;
    priority_queue<long, vector<long>, greater<long>> second;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
