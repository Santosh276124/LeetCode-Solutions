class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, list<pair<int,int>> > adj;
        
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        vector<int> vis(n+1, 0);
        
        queue<int> q;
        
        q.push(1);
        vis[1] = 1;
        int ans = 1e9;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neigh : adj[node]){
                
                ans = min(ans, neigh.second);
                
                if(!vis[neigh.first]){
                    vis[neigh.first] = 1;
                    q.push(neigh.first);
                }
                
            }
        }
        
        return ans==1e9?-1:ans;
    }
};