class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        if(n == 0) return 0;
        
        int maxLen = 0;
        
        unordered_map<char,int> mp;  //char->index
        
        int j = 0;
        
        for(int i = 0; i < n; i++){
            
            if(mp.count(s[i])){
                j = max( j, mp[s[i]] + 1);
            }
            
            mp[s[i]] = i;
            
            maxLen = max(maxLen, i-j+1);
  
        }
       
        
        return maxLen;
        
    }
};