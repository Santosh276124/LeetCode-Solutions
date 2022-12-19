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
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return Mem(n, m, pattern, str, dp);
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