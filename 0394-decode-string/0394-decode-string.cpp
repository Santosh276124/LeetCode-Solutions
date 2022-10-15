class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        string res = "";
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            
            else
            {
                string curr = "";
                
                while(st.top() != '[')
                {
                    curr = st.top() + curr;
                    st.pop();
                }
                
                st.pop();
                
                string num = "";
                
                while(!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                
                int k = stoi(num);
                while(k--)
                {
                    for(int j = 0; j < curr.size(); j++)
                    {
                        st.push(curr[j]);
                    }
                }
            }
            
            
        }
        
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};