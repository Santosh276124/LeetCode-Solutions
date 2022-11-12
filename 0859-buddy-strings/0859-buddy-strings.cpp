class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length() != goal.length()) return false;
       
        if(s == goal)
        {
             set<char> st(s.begin(), s.end());
            
            if(s.length() - st.size() >= 1) return true;
        }
        
       vector<int> diff;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i])
               diff.push_back(i);
            
            if(diff.size() > 2) return false;
        }
        
        if(diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]])
            return true;
        return false;
        
        
    }
};