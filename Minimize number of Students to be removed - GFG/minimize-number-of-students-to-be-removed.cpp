//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int n) {
       
    //   Longest Increasing Subsequence using binary Search
    
    vector<int> temp;
    temp.push_back(a[0]);
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] > temp.back())
        {
            temp.push_back(a[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), a[i])-temp.begin();
            
            temp[ind] = a[i];
        }
    }
        
        return n-temp.size();
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends