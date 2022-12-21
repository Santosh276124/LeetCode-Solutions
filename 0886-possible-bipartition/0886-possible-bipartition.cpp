class Solution {
    bool bfs(int i, unordered_map<int,list<int>> &adj, vector<int> &color)
    {
        
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto neigh : adj[node])
            {
                if(color[neigh] == color[node]) return false;
                 
                if(color[neigh] == 0){
                    color[neigh] = -color[node];
                    q.push(neigh);  
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int,list<int>> adj;
        for(int i = 0; i < dislikes.size(); i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            if(color[i] != 0) continue;
                
            bool ans = bfs(i, adj, color);
            
            if(ans == false) return false;
                
            
        }
        
        return true;
    }
};