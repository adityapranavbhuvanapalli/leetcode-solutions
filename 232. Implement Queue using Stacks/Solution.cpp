class MyQueue {
public:
    stack<int> s, t;
    MyQueue() {

    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int x, e;
        while(s.size()) {
            x = s.top();
            s.pop();
            t.push(x);
        }

        e = t.top();
        t.pop();

        while(t.size()) {
            x = t.top();
            t.pop();
            s.push(x);
        }
        return e;
    }
    
    int peek() {
        int x, e;
        while(s.size()) {
            x = s.top();
            s.pop();
            t.push(x);
        }

        e = t.top();

        while(t.size()) {
            x = t.top();
            t.pop();
            s.push(x);
        }
        return e;
    }
    
    bool empty() {
        return !s.size();
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