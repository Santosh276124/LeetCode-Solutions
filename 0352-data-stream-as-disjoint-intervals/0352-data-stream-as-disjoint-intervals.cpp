class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
         set<vector<int>> ans;
        
        vector<int> arr;
        for(auto s : st) arr.push_back(s);
        
        
        int st = arr[0];
        int et = arr[0];
       
        for(int i = 1; i < arr.size(); i++)
        {
            vector<int> temp;
            temp.push_back(st);
            
            while( i < arr.size() && arr[i]-arr[i-1] == 1)
            {
                et = arr[i++];
            }
            
            temp.push_back(et);
             ans.insert(temp);
           
            if(i < arr.size()){
                st = arr[i];
                et = arr[i];
            }
         
           
        }
        
        ans.insert({st, et});
        
        
        vector<vector<int>> res;
        
        for(auto nums : ans)
            res.push_back(nums);
        
        return res;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */