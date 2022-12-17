//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int waysToBreakNumber(int n){
        // code here 
         long long int mod = 1000000007;
        int ans = ((n + 1) % mod * (n + 2) % mod) / 2;
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends