class Solution {
public:
    void solve(int ind, string s, vector<string> temp, vector<vector<string>> &ans){
        
        if(ind >= s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i < s.length(); i++){
            
            string part = s.substr(ind, i-ind+1);
            
            if(isValid(part)){
                temp.push_back(part);
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
        
    }
    bool isValid(string &s){
        if(s.length() == 0)
            return false;
        int l = 0;
        int h = s.length()-1;
        while(l <= h){
            if(s[l] != s[h])
                return false;
            
            l++;
            h--;
        }
        
        return true;
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp ;
        
        solve(0, s, temp, ans);
        
        return ans;
        
    }
};