class Solution {
public:
    void dfs(int node, unordered_map<int, list<pair<int,int>> >& adj, vector<int> &vis, int &ans){
        
        vis[node] = 1;
        
        for(auto neigh : adj[node]){
            
            ans = min(ans, neigh.second);
            
            if(!vis[neigh.first]){
          
                dfs(neigh.first, adj, vis, ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, list<pair<int,int>> > adj;
        
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        int ans = 1e9;
        
        vector<int> vis(n+1, 0);
        
        dfs(1, adj, vis, ans);
        
//         queue<int> q;
        
//         q.push(1);
//         vis[1] = 1;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
            
//             for(auto neigh : adj[node]){
                
//                 ans = min(ans, neigh.second);
                
//                 if(!vis[neigh.first]){
//                     vis[neigh.first] = 1;
//                     q.push(neigh.first);
//                 }
                
//             }
//         }
        
        return ans==1e9?-1:ans;
    }
};