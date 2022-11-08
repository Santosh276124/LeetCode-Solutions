class Solution {
public:
    string makeGood(string s) {
        
        int n = s.length();
        stack<char> st;
        
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            
           
       char temp = st.top();     
        
       if( !st.empty() && (tolower(ch) == tolower(st.top()) && ((isupper(ch) && islower(st.top())) || (isupper(st.top()) && islower(ch))) )){
            
            // while(!st.empty() && ( (isupper(ch) && islower(st.top())) || (isupper(st.top()) && islower(ch)) ) &&(tolower(ch) == tolower(st.top()) ) ) 
                // {
              
                    st.pop();

                // }
            }
            else
            st.push(ch);
             
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};