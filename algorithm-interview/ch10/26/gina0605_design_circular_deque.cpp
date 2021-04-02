/*
641. Design Circular Deque
24ms, 16.8MB
*/

class MyCircularDeque{
public:
	vector<int> A;
	int s, e;
	int sz;

    MyCircularDeque(int k) {
        A.resize(k + 1);
		s = 0;
		e = k;
		sz = k + 1;
    }
    
    bool insertFront(int value) {
		if(isFull()) return false;
		s = (s + sz - 1) % sz;
		A[s] = value;
		return true;
    }
    
    bool insertLast(int value) {
		if(isFull()) return false;
		e = (e + 1) % sz;
		A[e] = value;
		return true;
    }
    
    bool deleteFront() {
		if(isEmpty()) return false;
        s = (s + 1) % sz;
		return true;
    }
    
    bool deleteLast() {
		if(isEmpty()) return false;
		e = (e + sz - 1) % sz;
		return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : A[s];
    }
    
    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
