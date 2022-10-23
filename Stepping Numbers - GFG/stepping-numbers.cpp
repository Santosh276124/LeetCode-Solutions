//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    void dfs(int curr, int n, int m, int &cnt)
    {
        if(curr > m) return;
        
        if(curr>=n && curr <=m) cnt++;
        
        int lastDigit = curr%10;
        
        if(lastDigit == 9) dfs(curr*10+8, n, m, cnt);
        
        else if(lastDigit == 0) dfs(curr*10 + 1, n, m, cnt);
        
        else
        {
            dfs(curr*10 + (lastDigit+1), n, m, cnt);
            dfs(curr*10 + (lastDigit-1), n, m, cnt);
        }
    }
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        
        int ans = 0;
        if(n == 0) ans++;
        
        for(int i = 1; i <= 9; i++)
        {
            dfs(i, n, m, ans);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends