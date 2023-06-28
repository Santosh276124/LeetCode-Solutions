class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;
        
        vector<int> next(n), prev(n);
        
        stack<int> st;
        st.push(-1);
        
        for(int i = n-1; i >= 0; i--){
            
            while(st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();
            
            
            next[i] = st.top();
            
            st.push(i);
            
        }
        
        while(!st.empty()) st.pop();
        
        st.push(-1);
        
        //prev
        for(int i = 0; i < n; i++){
            
            while(st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();
            
            
            prev[i] = st.top();
            
            st.push(i);
            
        }
        
        for(int i = 0; i < n; i++){
            
            int ht = heights[i];
            
            if(next[i] == -1) next[i] = n;
            int wt = next[i] - prev[i] -1;
            
            ans = max(ans, ht*wt);
            
        }
        
        
        return ans;
    }
};