//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty())
        {
            auto front = q.front();
            int node = front.first;
            int parent = front.second;
            
            q.pop();
            
            for(auto neigh : adj[node])
            {
                if(!vis[neigh])
                {
                    vis[neigh] = 1;
                    q.push({neigh, node});
                }
                else if(parent != neigh)  //already visited
                    return true;
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(bfs(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends