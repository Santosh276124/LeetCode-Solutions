class Solution {
public:
    void dfs(int node, unordered_map<int,list<pair<int,int>> >& adj, vector<int> &vis, int &ans){
        
        vis[node] = 1;
        
        for(auto neigh : adj[node]){
            
            if(vis[neigh.first] == 0){
                
                if(neigh.second == 1)
                    ans++;
                
                dfs(neigh.first, adj, vis, ans);
                
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,list<pair<int,int>> > adj;
        
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        
        vector<int> vis(n, 0);
        
        int ans = 0;
        
        // dfs(0, adj, vis, ans);
        
        queue<int> q;
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neigh : adj[front]){
                if(!vis[neigh.first]){
                    
                    if(neigh.second == 1)
                        ans++;
                    
                    vis[neigh.first] = 1;
                    
                    q.push(neigh.first);
                    
                }
            }
        }
        
        return ans;
        
    }
};