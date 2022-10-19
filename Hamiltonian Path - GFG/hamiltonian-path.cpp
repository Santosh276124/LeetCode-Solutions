//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool dfs(int node, unordered_map<int,list<int>> &adj,  vector<bool> vis, int cnt)
    {
        if(cnt == vis.size()-1) return true;
        
        vis[node] = true;
        
        cnt++;
        
        for(auto neigh : adj[node])
        {
            if(!vis[neigh])
            {
                if(dfs(neigh, adj, vis, cnt))
                 return true;
            }
        }
        
        return false;
    }
    public:
    bool check(int n,int M,vector<vector<int>> edges)
    {
        // code here
        unordered_map<int,list<int>> adj;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n+1, false);
        
       for(int i = 1; i <= n; i++)
       {
           if(dfs(i, adj, vis, 1))
             return true;
       }
       return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends