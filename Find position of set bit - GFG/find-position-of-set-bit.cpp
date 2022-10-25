//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isPowerOfTwo(int n)
    {
         if(n <= 0) return false;
        
        else if(((n&(n-1)) == 0))
        return true;
        
        else return  false;
    }
  public:
    int findPosition(int n) {
        // code here
        
        if(isPowerOfTwo(n) == false)
        return -1;
        
        int cnt = 0;
        while(n)
        {
            cnt++;
            
            if((n&1) == 1)
             break;
         
            n>>=1;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends