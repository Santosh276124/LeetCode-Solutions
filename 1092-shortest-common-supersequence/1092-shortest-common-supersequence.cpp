class Solution {
  
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.length();
        int n = str2.length();
       
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        int i = m, j = n;
        string ans = "";
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans = str1[i-1] + ans;
                i = i-1;
                j = j-1;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans = str1[i-1]+ans;
                i = i-1;
            }
            else{
                ans = str2[j-1] + ans;
                j = j-1;
            }
        }
        while(i > 0)
        {
            ans = str1[i-1]+ans;
            i--;
        }
        while(j > 0)
        {
            ans = str2[j-1] + ans;
            j--;
        }
        // cout<<ans<<" ";
        return ans;
    }
    
};