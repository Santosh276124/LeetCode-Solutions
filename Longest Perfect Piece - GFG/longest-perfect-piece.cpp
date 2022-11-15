//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
         
        map<int,int> m;
        int j = 0;
        int len = 0;
        
        for(int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            
            while((--m.end())->first-m.begin()->first > 1)
            {
                m[arr[j]]--;
                if(m[arr[j]] == 0)
                  m.erase(arr[j]);
                  
                j++;
            }
            
            len = max(len, i-j+1);
            
        }
       return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends