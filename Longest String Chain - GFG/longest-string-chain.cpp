//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  static bool comp(string &a, string &b)
  {
      return a.length() < b.length();
  }
  bool compare(string& s1, string &s2)
  {
      if(s1.length() != s2.length()+1) return false;
      
      int n = s1.length();
      int m = s2.length();
      int i = 0;
      int j = 0;
      while(i < n)
      {
          if(j < m && s1[i] == s2[j])
          {
              i++;
              j++;
          }
          else
          {
              i++;   
          }
      }
      
      if(i == n && j == m) return true;
      return false;
      
  }
    int longestChain(int n, vector<string>& arr) {
        
        sort(arr.begin(), arr.end(), comp);
        
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++)
            {
                if(compare(arr[i], arr[prev]) && 1+dp[prev] > dp[i])
                {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
           if(dp[i] > maxi)
           {
               maxi = dp[i];
            //   lastIndex = i;
           }
        }
        
        // vector<int> ans;
        // ans.push_back(arr[lastIndex]);
        
        // while(hash[lastIndex] != lastIndex)
        // {
        //     lastIndex = hash[lastIndex];
        //     ans.push_back(arr[lastIndex]);
        // }
        
        // cout<<maxi<<" ";
        return maxi;
        // reverse(ans.begin(), ans.end());
        // return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends