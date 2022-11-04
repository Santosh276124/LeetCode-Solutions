//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int fl = -1, cl = -1;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= x)
        {
          maxi = max(maxi , arr[i]);
          fl = maxi;
        }
          
         if(arr[i] >= x)
        {
          mini = min(mini, arr[i]);
          cl = mini;
        }
    }
    pair<int,int> p = {fl, cl};
    
    //   23 42
    //   85 24 40 10 66 16 6 54 93 42 6 98 49 100 98 23 59 48 17 56 64 94 77
  
  return p;
}