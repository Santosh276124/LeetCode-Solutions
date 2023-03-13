//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int,list<pair<int,int>> > adj;
        
        
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> dist(n+1, 1e9);
        
        vector<int> parent(n+1);
        
        for(int i = 0; i <= n; i++)
            parent[i] = i;
            
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int nodeDist = top.first;
            
            for(auto neigh : adj[node])
            {
                int neighNode = neigh.first;
                int neighDist = neigh.second;
                
                if(nodeDist + neighDist < dist[neighNode])
                {
                    dist[neighNode] = nodeDist + neighDist;
                    
                    parent[neighNode] = node; 
                    
                    pq.push({dist[neighNode], neighNode});
                }
            }
        }
        
        //backtrack on parent vector
        int target = n;
        int start = 1;
        
        if(dist[target] == 1e9)
         return {-1};
        
        vector<int> ans;
        
        ans.push_back(target);
        
        while(target != start)
        {
            target = parent[target];
            
            ans.push_back(target);
        }
        
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
   
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends