//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long gcd(long long a, long long b)
    {
        if(b == 0) return a;
        
        return gcd(b, a%b);
    }
    long long solve(int n)
    {
         long long x = (n*(n-1)) / gcd(n, n-1);
        long long y = ((n-2)*(n-3)) / gcd(n-2, n-3);
        long long z = (x*y) / gcd(x, y);
        
        long long num = n*(n-1);
        int cnt = 0;
        for(int i = n-2; i >= 1; i--)
        {
            if(gcd(num, i) == 1)
            {
                num*=i;
                cnt++;
            }
            if(cnt == 2) break;
        }
        return max(z, num);
    }
  public:
    long long maxGcd(int n) {
        // code here
        return max(solve(n), solve(n-1));
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends