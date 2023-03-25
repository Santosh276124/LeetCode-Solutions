class MyQueue {
public:
    // stack<int> s1, s2;
    stack<int> stin, stout;
    MyQueue() {
        
    }
    
    void push(int x) {
        
//         //s1 to s2
//         while(!s1.empty()){
//             int top = s1.top();
//             s1.pop();
//             s2.push(top);
//         }
        
//         s1.push(x);
        
//         //s2 to s1
//         while(!s2.empty()){
//             int top = s2.top();
//             s2.pop();
//             s1.push(top);
//         }
        
        
        stin.push(x);
        
    }
    
    int pop() {
        if(!stout.empty()){
            int top = stout.top();
            stout.pop();
            return top;
        }
        else{
            while(!stin.empty()){
                int top = stin.top();
                stin.pop();
                stout.push(top);
            }
            
            int top = stout.top();
            stout.pop();
            return top;
        }
    }
    
    int peek() {
        
        if(!stout.empty()){
            return stout.top();
        }
        else{
            while(!stin.empty()){
                int top = stin.top();
                stin.pop();
                stout.push(top);
            }
            return stout.top();
        }
        
    }
    
    bool empty() {
       
            while(!stin.empty()){
                int top = stin.top();
                stin.pop();
                stout.push(top);
            }
             return stout.size() == 0;

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