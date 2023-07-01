class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        string ans = "";
        
        int n = s.size();
        
        sort(s.begin(), s.end());
        
        string f = s[0];
        string l  = s[n-1];
        
        int i = 0;
        while(i < f.length()){
            
            if(f[i] == l[i]){
                ans += f[i];
            }
            else break;
            
            i++;
        }
        
        return ans;
    }
};