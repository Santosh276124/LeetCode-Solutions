class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        //s1 to s2
        while(!s1.empty()){
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        
        s1.push(x);
        
        //s2 to s1
        while(!s2.empty()){
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
        
        
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size() == 0;
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