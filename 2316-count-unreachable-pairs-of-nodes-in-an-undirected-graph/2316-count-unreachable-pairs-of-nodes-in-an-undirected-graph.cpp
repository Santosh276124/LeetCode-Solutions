class Solution {
public:
    void dfs(int node,  unordered_map<int, list<int> >& adj, vector<int> &vis, long long &cnt){
        
        vis[node] = 1;
        cnt++;
        
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, cnt);
            }
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
          
        unordered_map<int, list<int> > adj;
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        
        vector<int> vis(n, 0);
        
        vector<long long> temp;
        
        for(int i = 0; i < n; i++){
            
            long long cnt = 0;
            
            if(vis[i] == 0){
                
                dfs(i, adj, vis, cnt);
      
            }

            temp.push_back(cnt);    
        }
        
        int len = temp.size();
        
        long long ans = 0;
        long long totalSum = 0;
        //prefix sum
        for(int i = 0; i < len; i++){
            totalSum += temp[i];
        }
        
        for(int i = 0; i < n; i++){
            
            ans += ( temp[i] * (totalSum - temp[i]) );
            
            totalSum -= temp[i];
            
        }
        
        return ans;
    }
};