class Solution
{
    public:
        string reverseWords(string s)
        {

            int n = s.length();
            string ans = "";

            stack<string> st;

            for (int i = 0; i < n; i++)
            {
                string temp = "";
                if (s[i] == ' ')
                    continue;
                while (i < n && s[i] != ' ')
                    temp += s[i++];

                st.push(temp);
            }
               
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                    if(!st.empty()) ans += " ";
                    
                    
                }

                return ans;
            }
        };