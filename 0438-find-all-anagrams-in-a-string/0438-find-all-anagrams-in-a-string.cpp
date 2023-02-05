class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        vector<int> f1(26, 0);
        vector<int> curr(26, 0);
        
        for(int i = 0; i < m; i++)
            f1[p[i]-'a']++;
        
        int j = 0;
        int i = 0;
        vector<int> ans;
        while(i < n)
        {
            curr[s[i]-'a']++;
            
            if(i-j+1 == m)
            {
                if(curr == f1) ans.push_back(j);
            }
            if(i-j+1 < m) i++;
            else
            {
                curr[s[j]-'a']--;
                j++;
                // curr[s[i]-'a']++;
                i++;
                
            }
        }
        return ans;
    }
};