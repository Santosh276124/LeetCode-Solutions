//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int node, int prevC, vector<int> adj[], vector<int> &color)
{
    color[node] = prevC;
    
    for(auto neigh : adj[node])
    {
        if(color[neigh] == -1)
        {
            if(dfs(neigh, !prevC, adj, color) == false) return false;
        }
        
        else if(color[neigh] == prevC)
            return false;
    }
    
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    
	    vector<int> color(V, -1);
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(color[i] == -1){
	          if(dfs(i, 0, adj, color) == false)
	            return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends