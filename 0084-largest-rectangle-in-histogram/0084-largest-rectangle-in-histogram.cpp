class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        
        int n = ht.size();
        int ans = 0;
        
        stack<int> st;
        
        for(int i =0; i <= n; i++){
            
            while(!st.empty() && (i == n || ht[st.top()] >= ht[i])){
                
                int h = ht[st.top()];
                st.pop();
                
                int wt;
                if(st.empty()) wt = i;
                else wt = i-st.top()-1;
                
                ans = max(ans, h*wt);
                
            }
            
            st.push(i);
        }
        return ans;
    }
};