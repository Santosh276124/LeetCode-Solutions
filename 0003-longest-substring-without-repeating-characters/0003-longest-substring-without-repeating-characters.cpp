class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int len = 0;
        int j = 0;
        
        unordered_map<char, int> m;
        
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
            
            if(m.size() == i-j+1)
                len = max(len, i-j+1);
            
            else if(m.size() < i-j+1)
            {
                while(m.size() < i-j+1)
                {
                    m[s[j]]--;
                    if(m[s[j]] == 0)
                        m.erase(s[j]);
                    
                    j++;
                }
            }
        }
        
        return len;
    }
};