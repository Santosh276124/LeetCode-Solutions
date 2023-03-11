//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> adjRev[V];
        
        for(int u = 0; u < V; u++)
        {
            for(auto v : adj[u])
            {
                adjRev[v].push_back(u);
            }
        }
        
        vector<int> in(V, 0);
        for(int i = 0; i < V; i++)
        {
            for(auto neigh : adjRev[i])
            {
                in[neigh]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i< V; i++)
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
            
            for(auto neigh : adjRev[node])
            {
                in[neigh]--;
                if(in[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        sort(topo.begin(), topo.end());
        
        return topo;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends