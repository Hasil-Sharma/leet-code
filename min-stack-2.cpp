// https://leetcode.com/problems/min-stack/description/
class MinStack {
    stack<pair<int, int>> stk;
public:
    /** initialize your data structure here. */
    
    void push(int x) {
        if (stk.size() == 0 || stk.top().second >= x)
            stk.push({x, x});
        else stk.push({x, getMin()});
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
