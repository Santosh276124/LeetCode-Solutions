class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        
        int i = 0;
        
        reverse(s.begin(), s.end());
        
        
        while(i < n && s[i] == ' ')
            i++;
        
      
        string temp = "";
        
        string ans = "";
        
        while(i < n){
            
            if(s[i] != ' '){
                while(i < n && s[i] != ' '){
                    temp += s[i];
                    i++;
                }
            }
            else{
                if(temp.size() != 0){
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    ans += " ";
                    
                    temp = "";
                }
                
                    i++;
            }
                
        }
        
        if(temp.size() != 0){
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        
        while(ans.size() > 0 && ans.back() == ' ')
            ans.pop_back();
        
        return ans;
    }
};