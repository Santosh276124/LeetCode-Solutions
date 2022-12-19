//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    bool rec(int i, int j, string &pattern, string &str)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0)
        {
            for(int k = 0; k <= i; k++)
            {
                if(pattern[k] != '*')
                    return false;
            }
            return true;
        }
        
        if(pattern[i] == str[j] || pattern[i] == '?')
          return rec(i-1, j-1, pattern, str);
        
        if(pattern[i] == '*')
          return rec(i-1, j, pattern, str) | rec(i, j-1, pattern, str);
         
        return false; 
        
    }
    
     bool Mem(int i, int j, string &pattern, string &str, vector<vector<int>>&dp)
    {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0)
        {
            for(int k = 1; k <= i; k++)
            {
                if(pattern[k-1] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
          return dp[i][j] = Mem(i-1, j-1, pattern, str, dp);
        
        if(pattern[i-1] == '*')
          return dp[i][j] = (Mem(i-1, j, pattern, str, dp) | Mem(i, j-1, pattern, str, dp));
         
        return dp[i][j] = false; 
        
    }
    
    bool Tab( string &pattern, string &str)
    {
        int n = pattern.length();
        int m = str.length();
        
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int j = 1; j <= m; j++) dp[0][j] = false;
        for(int i = 1; i <= n; i++)
        {
            bool flag = true;
            for(int k = 1; k <= i; k++)
            {
                if(pattern[k-1] != '*')
                    flag = false;
            }
            dp[i][0] = flag;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                   dp[i][j] = dp[i-1][j-1];
                
                else if(pattern[i-1] == '*')
                   dp[i][j] = dp[i][j-1] | dp[i-1][j];
                 
                else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
        
    }
    
    bool space( string &pattern, string &str)
    {
        int n = pattern.length();
        int m = str.length();
        
        vector<bool> prev(m+1, false), curr(m+1, false);
        
        prev[0] = true;
        for(int j = 1; j <= m; j++) prev[j] = false;
        
        
        for(int i = 1; i <= n; i++)
        {
           //assigning evry rows 0th column 
                bool flag = true;
                for(int k = 1; k <= i; k++)
                {
                    if(pattern[k-1] != '*')
                        flag = false;
                }
                curr[0] = flag;
            
            for(int j = 1; j <= m; j++)
            {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                   curr[j] = prev[j-1];
                
                else if(pattern[i-1] == '*')
                   curr[j] = curr[j-1] | prev[j];
                 
                else curr[j] = false;
            }
            prev = curr;
        }
        
        return prev[m];
        
    }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        // int n = pattern.length();
        // int m = str.length();
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return Mem(n, m, pattern, str, dp);
        
        // return Tab(pattern, str);
        return space(pattern, str);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends