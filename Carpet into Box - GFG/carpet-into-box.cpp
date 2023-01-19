//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int func(int A, int B, int C, int D)
    {
        int cnt = 0;
       
        while(A > C || B > D)
        {
            if(A > C)
            {
                A = floor(A/2);
                cnt++;
            }
            if(B > D)
            {
                B = floor(B/2);
                cnt++;
            }
        }
        return cnt;
    }
    int carpetBox(int A, int B, int C, int D){
        
        int cnt1 = func(A,B,C,D);
        
        swap(A,B);
        int cnt2 = func(A,B,C,D);
        
        
        return min(cnt2, cnt1);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends