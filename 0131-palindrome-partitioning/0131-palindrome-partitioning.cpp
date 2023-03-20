class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPalndrome(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i <  j){
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind, string &s, vector<string> temp){
        
        if(ind >= n){
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i < n; i++){
            
            string part = s.substr(ind, i-ind+1);

            
            if(isPalndrome(part)){
                
                temp.push_back(part);
                
                solve(i+1, s, temp);
                
                temp.pop_back();
            }
          
            
        }
    }
    vector<vector<string>> partition(string s) {
        
        n = s.length();
        vector<string> temp;
        
        solve(0, s, temp);
        
        return ans;
        
    }
};