class MyStack {
public:
    queue<int> q1, q2;                                                                                 
    MyStack() {
        
    }
    
    void push(int x) {
        
        q2.push(x);
        
        while(!q1.empty()){
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        
        swap(q1, q2);
        
    }
    
    int pop() {
        int front = q1.front();
        q1.pop();
        return front;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
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