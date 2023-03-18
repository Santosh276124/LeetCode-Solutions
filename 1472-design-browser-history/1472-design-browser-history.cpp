class BrowserHistory {
public:
    
    vector<string> arr;
    int curr;
    
    BrowserHistory(string homepage) {
        
        arr.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
     
        arr.erase(arr.begin() + curr+1, arr.end());
        
        arr.push_back(url);
        
        curr++;
    }
    
    string back(int steps) {
       
        curr = max(0, curr-steps);
        
        return arr[curr];
    }
    
    string forward(int steps) {
        
        curr = min(int(arr.size()-1), curr+steps);
        
        return arr[curr];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */