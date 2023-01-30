//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int dfs(int node, int parent, int lighted, unordered_map<int,list<int>>& adj, vector<vector<int>>& dp)
  {
      
      if(dp[node][lighted] != -1) return dp[node][lighted];
      
      int ans = 0;
      
      for(auto child : adj[node])
      {
          if(child != parent){
              
              if(lighted)
              {
                  int c1 = dfs(child, node, 0, adj, dp);
                  int c2 = 1 + dfs(child, node, 1, adj, dp);
                  
                  ans += min(c1, c2);
              }
              else{
                  int c3 = 1 + dfs(child, node, 1, adj, dp);
                  ans += c3;
              }          
   
          }
      }
      
      return dp[node][lighted] = ans;
  }
    int countVertex(int n, vector<vector<int>>edges){
        // code here
        
        unordered_map<int,list<int>> adj;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<vector<int>> dp1(n+1, vector<int>(2, -1));
        vector<vector<int>> dp2(n+1, vector<int>(2, -1));
        
        int case1 = 1 +  dfs(1, -1, 1, adj, dp1); // node is lighted
        int case2 = dfs(1, -1, 0, adj, dp2);   // node is not lighted
        
        return min(case1, case2);
        
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
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends