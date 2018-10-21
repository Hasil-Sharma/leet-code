// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    stack<int> stk1, stk2;
    /** Initialize your data structure here. */
    MyQueue() {
        stk1 = stack<int>();
        stk2 = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        stk2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (stk2.empty())
            while(!stk1.empty())
                stk2.push(stk1.top()), stk1.pop();
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk2.empty() && stk1.empty();
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
