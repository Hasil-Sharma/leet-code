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
        pushfromto(stk1, stk2);
        stk1.push(x);
        pushfromto(stk2, stk1);
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
    
    void pushfromto(stack<int>& stk1, stack<int>& stk2){
        while(!stk1.empty()){
            int x = stk1.top();
            stk1.pop();
            stk2.push(x);
        }
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
