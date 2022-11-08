class Solution {
public:
    int maxDepth(string s) {
        
       int ans = 0;
       int cnt = 0;
        for(char& i : s)
        {
            if(i == '(')
                ans = max(ans, ++cnt);
            if(i == ')')
                cnt--;
        }
        return ans;
        
    }
};