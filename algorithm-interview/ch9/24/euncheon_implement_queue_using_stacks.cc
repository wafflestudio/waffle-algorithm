/*

*/
class MyQueue {
public:
    stack<int> s1, s2;
    int count;
    int my_front;
    /** Initialize your data structure here. */
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
        count = 0;
        my_front = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) my_front = x;
        s1.push(x);
        count++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        for(int i=0; i<count-1; i++) {
            s2.push(s1.top());
            s1.pop();
        }
        int item = s1.top();
        s1.pop();
        count--;
        
        if (count > 0) {
            my_front = s2.top();
            for(int i=0; i<count; i++) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        return item;
    }
    
    /** Get the front element. */
    int peek() {
        return my_front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */