//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
       
       unordered_map<char,int> m;
       int j = 0;
       int len = INT_MIN;
       
       for(int i = 0; i < s.length(); i++)
       {
           m[s[i]]++;
           
           if(m.size() == k)
             len = max(len, i-j+1);
           
            else if(m.size() > k)
            {
                while(m.size() > k)
                {
                    m[s[j]]--;
                    if(m[s[j]] == 0)
                      m.erase(s[j]);
                      
                    j++;
                }
            }
          
       }
       return len==INT_MIN?-1:len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends