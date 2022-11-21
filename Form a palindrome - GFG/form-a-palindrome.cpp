//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int solve(string s1, string s2)
    {
        int n = s1.length();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int j = 0; j <= n; j++) prev[j] = 0;
       
        
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                   curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return curr[n];
    }
  public:
    int countMin(string str){
    //complete the function here
       int n = str.length();
       
       string s2 = str;
       reverse(s2.begin(), s2.end());
       int LCP = solve(str, s2);
       
       return n - LCP;
    
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends