class Solution {
public:
    bool isValid(string &s){
        
        stack<char> ans;
        
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            
            if(ch == '(' || ch == '{'|| ch == '[')
            {
                ans.push(ch);
                
            }
            else
            {
                if(!ans.empty())
                {
                    char top = ans.top();
                    if( (ch == ')' && top == '(' ) 
                       || (ch == '}' && top == '{' ) 
                       ||(ch == ']' && top == '[' ) )
                    {
                        ans.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                
            }
        }
                                                                                if(ans.empty()) return true;
        else return false;
    }
    void solve(int o, int c, int n, string temp, vector<string>&ans){
        if(o == n && c == n){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            
            return;
        }
        
        if(o < n)
            solve(o+1, c, n, temp + '(', ans);
        
        if(c < n)
            solve(o, c+1, n, temp + ')', ans);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        solve(0, 0, n, "", ans);
        
        return ans;
        
    }
};