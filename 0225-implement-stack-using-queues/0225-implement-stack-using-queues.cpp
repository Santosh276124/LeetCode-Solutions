class MyStack {
public:
    // queue<int> q1, q2; 
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        
//         q2.push(x);
        
//         while(!q1.empty()){
//             int front = q1.front();
//             q1.pop();
//             q2.push(front);
//         }
        
//         swap(q1, q2);
        
        q.push(x);
        int size = q.size();
        for(int i = 1; i < size; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        
    }
    
    int pop() {
        int front = q.front();
        q.pop();
        return front;
        
        
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
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