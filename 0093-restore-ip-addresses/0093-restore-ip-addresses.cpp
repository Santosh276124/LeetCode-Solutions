class Solution {
public:
    int n;
    vector<string> ans;
    
    void solve(int ind, int parts, string curr, string &s){
        
        if(ind == n && parts == 4)
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        //1
        if(ind+1 <= n )
           solve(ind+1, parts+1, curr + s.substr(ind, 1) + ".", s);
        
        //2
        if(ind+2 <= n && isValid(s.substr(ind, 2)) )
           solve(ind+2, parts+1, curr + s.substr(ind, 2) + ".", s);
        
        //3
        if(ind+3 <= n && isValid(s.substr(ind, 3)))
           solve(ind+3, parts+1, curr + s.substr(ind, 3) + ".", s);
        
    }
    bool isValid(string str)
    {
        if(str[0] == '0') return false;
        
        int val = stoi(str);
        
        if(val >= 0 && val <= 255) return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
          
        n = s.length();
        
        if(n > 12) return {};
        
        string curr = "";
        int parts = 0;
        
        solve(0, parts, curr, s);
        
        return ans;
    }
};