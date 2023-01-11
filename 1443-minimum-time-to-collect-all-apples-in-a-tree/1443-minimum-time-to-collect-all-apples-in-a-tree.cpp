class Solution {
public:
    
    int dfs(int node, int parent, unordered_map<int,list<int>>& adj, vector<bool>& hasApple)
    {
        // if(hasApple[node])
        // time += 2;
        
        int time = 0;
        
        for(auto child : adj[node])
        {
            if(child == parent) continue;
            
            int time_from_child = dfs(child, node, adj, hasApple);
            
            if(time_from_child > 0 || hasApple[child])
                time += time_from_child + 2;
        }
        
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
   
        unordered_map<int,list<int>> adj;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(0, -1, adj, hasApple); //node, parent, adj, hasApple
        
        // return time;
       
    }
};