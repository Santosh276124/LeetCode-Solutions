//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findSetBits(int b){
      int cnt = 0;
      while(b)
      {
          if(b&1 == 1) cnt++;
          
          b = b >> 1;
          
      }
      return cnt;
  }
  
    int minVal(int a, int b) {
        // code here  
        int sb1 = findSetBits(a);
        int sb2 = findSetBits(b);
        
        if(sb1 == sb2) return a;
 
        
        int ans = 0;
        
       for(int i = 0; i < 32; i++)
       {
           int mask = 1<<i;
           int set = a & mask;
           if( set == 0 && sb1 < sb2 ){
               ans |= mask;
               sb2--;
           }
           else if(set != 0 && sb1 > sb2)
           {
               sb1--;
           }
           else{
               ans |= set;
           }
           
       }
       
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends