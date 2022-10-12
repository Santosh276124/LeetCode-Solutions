//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
         
          unordered_map<char,int> m;
          for(int i = 0; i < n; i++)
          {
              m[x[i]] = b[i];
          }
          
          int currSum = 0;
          int maxSum = INT_MIN;
          string ans = "";
          string temp = "";
          for(int i = 0; i < w.length(); i++)
          {
             
                
              if(m.count(w[i]))
              {
                  currSum += m[w[i]];
                 
              }
              else
              {
                  currSum += int(w[i]);
                 
              }
              
              temp += w[i];
              
              if(currSum > maxSum)
              {
                  maxSum = currSum;
                  ans = temp;
              }
              if(currSum < 0)
              {
                 currSum = 0;
                 temp = "";
              }
           
          }
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends