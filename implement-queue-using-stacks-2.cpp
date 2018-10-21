// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    stack<int> stk1;
    /** Initialize your data structure here. */
    MyQueue() {
        stk1 = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (stk1.empty()) stk1.push(x);
        else{
            int y = pop();
            push(x);
            stk1.push(y);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        stk1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return stk1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
