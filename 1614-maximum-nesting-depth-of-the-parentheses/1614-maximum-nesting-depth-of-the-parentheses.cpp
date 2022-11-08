class Solution {
public:
    int maxDepth(string s) {
        
        vector<int> pref;
        vector<int> suff;
        
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] =='(')
                cnt1++;

             pref.push_back(cnt1);
            
            if(s[i] == ')')
                cnt2++;
            
            suff.push_back(cnt2);
        }
        
        int ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            ans = max(ans, pref[i]-suff[i]);
        }
        return ans;
        
    }
};