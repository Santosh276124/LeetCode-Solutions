class Solution {
public:
    int numberOfSubstrings(string s) {
        
        unordered_map<char,int> m;
        int cnt = 0;
        int j = 0;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
            
            if(m.size() >= 3)
            {
                while(m.size() >= 3)
                {
                    m[s[j]]--;
                    
                    if(m[s[j]] == 0)
                        m.erase(s[j]);
                    
                    j++;
                }
            }
            
            cnt += j;
        }
        return cnt;
    }
};