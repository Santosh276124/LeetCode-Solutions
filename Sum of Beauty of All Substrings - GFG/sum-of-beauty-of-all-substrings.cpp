//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        
        int n = s.length();
        // unordered_map<char,int> m;
        int maxfreq;
        int minfreq;
        
        int j = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<char,int> m;
            
            for(int j = i; j < n; j++)
            {
                
                 m[s[j]]++;
                 
                 maxfreq = INT_MIN;
                 minfreq =INT_MAX;
               
              
                    for(auto k : m)
                    {
                        if(k.second > maxfreq) maxfreq = k.second;
                       
                        if(k.second < minfreq) minfreq = k.second;
                        
                    } 
               
                
                res += (maxfreq-minfreq);
                // cout<<res<<" ";
                
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends