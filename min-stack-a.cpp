// https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push({x, stk.size() == 0 ? x : (x > this->getMin() ? this->getMin() : x)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
