// https://leetcode.com/problems/min-stack/description/

class MinStack {
    stack<int> stk1;
    stack<int> stk2;
public:
    /** initialize your data structure here. */
    
    void push(int x) {
        stk1.push(x);
        if (stk2.size() == 0 || stk2.top() >= x)
            stk2.push(x);
    }
    
    void pop() {
        int x = stk1.top();
        stk1.pop();
        if (stk2.size() > 0 && x == stk2.top()) 
            stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
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
