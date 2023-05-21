class Solution {
    
    int time = 1;
    
    void dfs(int node, int parent, unordered_map<int, list<int> > &adj, vector<int> &vis, 
            int timeIn[], int low[], vector<vector<int>>& bridges){
        
        vis[node] = 1;
        
        timeIn[node] = low[node] = time;
        
        time++;
        
        for(auto neigh : adj[node]){
            if(neigh == parent)
                continue;
            
            if(vis[neigh] == 0){
                
                dfs(neigh, node, adj, vis, timeIn, low, bridges);
                
                low[node] = min(low[node], low[neigh]);
                
                if(low[neigh] > timeIn[node])
                {
                    bridges.push_back({neigh, node});
                }
                
            }
            else{
                low[node] = min(low[node], low[neigh]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, list<int> > adj;
        
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        int timeIn[n];
        int low[n];
        
        vector<vector<int>> bridges;
        
        dfs(0, -1, adj,  vis, timeIn, low, bridges);
        
        return bridges;
        
    }
};