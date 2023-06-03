class Solution {
public:
    int ans= 0;
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<int> & time, int curr){
        
        ans = max(ans, curr);
        
        for(auto& neigh : adj[node]){ 
            
           dfs(neigh, adj, time, curr + time[node]);
 
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int, list<int>> adj;
        
        for(int i = 0; i < n; i++){
            if(manager[i] == -1)
                continue;
            
            adj[manager[i]].push_back(i);
        }
        
        vector<int> vis(n, 0);
        
        dfs(headID, adj, informTime, 0);
        
        return ans;
        
        
//         queue<pair<int,int>> q;
        
//         q.push({headID, 0});
        
//         int ans = 0;
        
//         while(!q.empty()){
//             auto top = q.front();
            
//             int node = top.first;
//             int currTime = top.second;
            
//             q.pop();
            
//             ans = max(ans, currTime);

//                 for(auto& neigh : adj[node]){
 
//                         q.push({neigh, currTime + informTime[node]});

//                 }
  
//         }
        
//         return ans;
        
    }
};