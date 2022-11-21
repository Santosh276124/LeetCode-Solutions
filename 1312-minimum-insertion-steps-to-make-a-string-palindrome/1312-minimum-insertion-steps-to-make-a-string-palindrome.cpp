class Solution {
    int longestCommonPalindrome(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + longestCommonPalindrome(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = max(longestCommonPalindrome(i-1, j, s1, s2, dp), longestCommonPalindrome(i, j-1, s1, s2, dp));
    }
    // int longestCommonPalindromeTab(string)
public:
    int minInsertions(string s) {
        
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int len = longestCommonPalindrome(n-1, n-1, s1, s, dp);
        
        return n-len;
       
    }
};