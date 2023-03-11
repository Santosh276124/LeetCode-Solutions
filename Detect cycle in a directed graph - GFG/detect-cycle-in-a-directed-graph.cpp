//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto neigh : adj[node])
        {
            if(!vis[neigh])
            {
                if(dfs(neigh, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[neigh])
                return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // vector<int> vis(V, 0);
        // vector<int> pathVis(V, 0);
        
        // for(int i = 0; i < V; i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(dfs(i, adj, vis, pathVis)) return true;
        //     }
        // }
        // return false;
        
        
        //using BFS 
        
        vector<int> in(V, 0);
        for(int i = 0; i < V; i++)
        {
            for(auto neigh : adj[i])
            {
                in[neigh]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto neigh : adj[node])
            {
                in[neigh]--;
                if(in[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        return topo.size() != V;
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends