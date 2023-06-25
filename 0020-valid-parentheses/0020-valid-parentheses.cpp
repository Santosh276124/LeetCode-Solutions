class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        
        if(n%2 == 1) return false;
        
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            
            if( (ch == '(') || (ch == '{') || (ch == '[')){
                st.push(ch);
            }
            
            else{
                if(!st.empty()){
                    auto top = st.top();
                    if( (ch == ')' && top == '(' ) || (ch == '}' && top == '{') || (ch == ']' && top == '[') )
                        st.pop();
                    else
                        return false;
                    
                }
                else
                    return false;
    
            }
            
        }
        
        return st.size() == 0?true:false;
    }
};