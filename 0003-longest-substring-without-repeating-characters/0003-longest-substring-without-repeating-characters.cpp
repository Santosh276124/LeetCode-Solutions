class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        int currLen = 0;
        int maxLen = 0;
        
        unordered_map<char,int> mp;
        
        int j = 0;
        int i = 0;
        for( ; i < n; i++){
            
            char ch = s[i];
            
            mp[ch]++;
            
            currLen = i-j+1;
            
            while(currLen > mp.size()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    mp.erase(s[j]);
                
                j++;
                
                currLen = i-j+1;
            }
            
            maxLen = max(maxLen, currLen);
  
        }
        
        // maxLen = max(maxLen, i-j);
        
        return maxLen;
        
    }
};