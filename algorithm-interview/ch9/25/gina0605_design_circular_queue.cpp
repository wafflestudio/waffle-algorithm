/*
622. Design Circular Queue
28ms, 16.8MB
*/

class MyCircularQueue {
public:
	vector<int> A;
	int s, e;
	int sz;

    MyCircularQueue(int k) {
        A.resize(k + 1);
		s = 0;
		e = k;
		sz = k + 1;
    }
    
    bool enQueue(int value) {
		if(isFull()) return false;
		e = (e + 1) % sz;
		A[e] = value;
		return true;
    }
    
    bool deQueue() {
		if(isEmpty()) return false;
        s = (s + 1) % sz;
		return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : A[s];
    }
    
    int Rear() {
        return isEmpty() ? -1 : A[e];
    }
    
    bool isEmpty() {
        return (e + 1) % sz == s;
    }
    
    bool isFull() {
        return (e + 2) % sz == s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
