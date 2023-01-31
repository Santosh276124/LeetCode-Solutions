//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool check(string& s1, string &s2)
  {
      int n = s1.length();
      int m = s2.length();
      int i = 0;
      int j = 0;
      
    //   while(i < n )
    //   {
    //       if(j < m && s1[i] == s2[j])
    //       {
    //           i++;
    //           j++;
    //       }
    //       else{
    //           i++;
    //       }
    //   }
      
    //   if(j == m) return true;
    //   return false;
    
    for(int i = 0; i < n; i++)
    {
        string s = s1.substr(i, m);
        
        if(s == s2) return true;
    }
    
    return false;
  }
  
    int minRepeats(string A, string B) {
        // code here
        
        string a = A;
        int cnt = 1;
        
        while(a.length() < B.length())
        {
            cnt++;
            a += A;
        }
        
        if(check(a, B)) return cnt;
        
        a += A;
        
        if(check(a, B)) return cnt+1;
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends