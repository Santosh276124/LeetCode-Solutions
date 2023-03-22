
class DisjointSet {
    vector<int> parent, rank;
    public:
        DisjointSet(int V){
            parent.resize(V+1);
            rank.resize(V+1);
            for(int i = 0; i <= V; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }
    
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        
        if(ult_u == ult_v) return;
        
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
        
        
    }
};

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
        
        
        DisjointSet ds(n);
        
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            
            ds.unionByRank(u, v);
        }
        
        int ult_par = ds.findParent(1);
        
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            
            if(ds.findParent(u) == ult_par && ds.findParent(v) == ult_par){
                ans = min(ans, d);
            }
    
        }
        
        
        
        
        // vector<int> vis(n+1, 0);
        
        // dfs(1, adj, vis, ans);
        
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