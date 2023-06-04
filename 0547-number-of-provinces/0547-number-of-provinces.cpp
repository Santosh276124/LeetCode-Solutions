class Solution {
public:
    void dfs(int node, unordered_map<int,list<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        
        for(auto neigh : adj[node]){
            if(neigh == node)
                continue;
            
            else if(!vis[neigh])
                dfs(neigh, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        unordered_map<int,list<int>> adj;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
          
                    adj[i].push_back(j);
       
                   
                }
            }
        }
        
        
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        
        return cnt;
        
    }
};