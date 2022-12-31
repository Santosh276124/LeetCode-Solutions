//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        map<int,int> m;
        
        for(int i = 0; i < N; i++)
          m[start[i]]++;
          
        for(int i = 0; i < N; i++)
          m[end[i]]--;
          
          int maxSum = 0;
          int sum = 0;
        for(auto i : m)
        {
            sum += i.second;
            maxSum = max(maxSum , sum);
            
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends