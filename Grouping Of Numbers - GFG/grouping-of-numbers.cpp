//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
      
      vector<int> rem(K, 0);
      
      for(int i = 0; i < N; i++)
      rem[arr[i]%K]++;
      
      int ans = 0;
      
      for(int i = 0; i <=K/2; i++)
      {
          if(i == 0 || i == K-i)
          {
              if(rem[i] != 0)
              ans++;
          }
          else
          ans += max(rem[i], rem[K-i]);
      }
      return ans;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends