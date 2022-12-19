class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,list<int>> adj;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> vis;
        
        queue<int> q;
        q.push(source);
        
        vis[source] = true;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            if(front == destination) return true;
            
            for(auto neigh : adj[front])
            {
                if(!vis[neigh])
                {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return false;
    }
};