class Solution {
public:
    
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<int> &vis, int& cnt){
        
        vis[node] = 1;
        
        cnt++;
        
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, cnt);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bomb) {
        
        int n = bomb.size();        
        unordered_map<int, list<int>> adj;
        
        for(int i = 0; i < bomb.size(); i++){
            long long x1 = bomb[i][0];
            long long y1 = bomb[i][1];
            long long r1 = bomb[i][2];
            
            for(int j = 0; j < bomb.size(); j++){
                
                if(j != i){
                    long long x2 = bomb[j][0];
                    long long y2 = bomb[j][1];
                    long long r2 = bomb[j][2];
                    
                    long long  x = abs(x2-x1);
                    long long  y = abs(y2-y1);
                    
                    // long long int d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                    
                    if(x*x + y*y <= r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        
        
        int ans = INT_MIN;
        
        for(int i = 0; i < bomb.size(); i++){
            
            int cnt = 0;
            
            vector<int> vis(n, 0);
            
            dfs(i, adj, vis, cnt);
            
            ans = max(ans, cnt);
            
        }
        
        
        return ans;
    }
};