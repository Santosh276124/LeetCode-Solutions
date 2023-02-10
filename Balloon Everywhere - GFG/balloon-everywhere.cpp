//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        int len = s.length();
        
        vector<int> count(26, 0);
        
        for(int i = 0; i < len; i++)
          count[s[i]-'a']++;
          
      
        
        int b = count[1];
        int a = count[0];
        int l = count[11];
        int o = count[14];
        int n = count[13];
        
        
        
        int singleLetter = min(b, min(a, n));
        int doubleLetter = min(l, o);
        
        return min(singleLetter, doubleLetter/2);
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends