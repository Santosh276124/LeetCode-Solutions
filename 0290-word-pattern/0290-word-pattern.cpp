class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> st;
        
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                st.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
            
        }
        
        st.push_back(temp);
        
        if(pattern.size() != st.size()) return false;
        
        unordered_map<string,char> mp;
        unordered_map<char,bool> vis;
        
        for(int i = 0; i < st.size(); i++)
        {
            if(mp.count(st[i]) == false && vis[pattern[i]] == true)
            {
                    return false;
            }
            else if(mp.count(st[i]))
            {
                if(mp[st[i]] != pattern[i]) return false;
            }
            else{
                vis[pattern[i]] = true;
                mp[st[i]] = pattern[i];
            }
               
            
        }
        
        return true;
        
        
    }
};