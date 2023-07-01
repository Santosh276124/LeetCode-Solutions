class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        string ans = "";
        
        for(int i = 0; i < s[0].length(); i++){
            
            char ch = s[0][i];
            bool fl = true;
            
            
            for(int j = 1; j < s.size(); j++){
                
                if(ch != s[j][i]){
                    fl = false;
                    break;
                }
                
            }
            
            if(fl) ans += ch;
            else break;
            
        }
        
        return ans;
    }
};