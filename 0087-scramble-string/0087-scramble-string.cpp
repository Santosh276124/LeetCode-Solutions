class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2){
        if(s1.length() != s2.length())
            return false;
        
        if(s1 == s2) return true;
        
        string key = s1 + "-" + s2;
        
        if(mp.count(key))
            return mp[key];
        
        int n = s1.length();
        
        bool ans = false;
        for(int i = 1; i < n; i++){
            
            //swaped
            bool swapped = 
                solve(s1.substr(i, n-i), s2.substr(0, n-i))  && 
                solve(s1.substr(0, i), s2.substr(n-i, i));
              
            
            //notswapped
            bool notSwapped = 
                solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i, n-i), s2.substr(i, n-i));
            
            if(swapped || notSwapped)
            {
                ans = true;
                break;
            }      
            
        }
        
        return mp[key] = ans;
    }
    bool isScramble(string s1, string s2) {
 
        mp.clear();
        
        return solve(s1, s2);
    }
};