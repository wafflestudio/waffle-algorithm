/*

*/

class MyStack {
    queue<int> q1, q2;
    int count;
    int top_value;
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
        count = 0;
        top_value = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        top_value = x;
        count++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i=0; i<count-1; i++) {
            q2.push(top_value = q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        q1 = q2;
        q2 = queue<int>();
        count--;
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return top_value;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */