//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxi;
  
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      maxi = INT_MIN;
      unordered_map<int,list<int>> adj;
      
      for(int i = 0; i < Edge.size(); i++)
      {
          int u = i;
          int v = Edge[i];
          
          if(v == -1) continue;
          
          adj[v].push_back(u);
      }
      
      int ans = 0;
      
      for(auto m : adj)
      {
          int  currSum = 0;
          
          for(auto j : m.second)
          {
              currSum += j;
          }
          
          if(currSum > maxi)
          {
              maxi = currSum;
              ans = m.first;
          }
      }
      
      return ans;
      
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends