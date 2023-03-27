class Solution {
public:
    int ans = -1;
    void dfs(int node, vector<int> &adj, vector<int> &vis, vector<int> &dfsVis, vector<int> &count){
        
        vis[node] = 1;
        dfsVis[node] = 1;
        
         int neigh = adj[node];
        
            if(neigh != -1){
                if(!vis[neigh]){
                    count[neigh] = count[node] + 1;
                    dfs(neigh, adj, vis, dfsVis, count);
                }
                else if(dfsVis[neigh]){
                    //cycle presnt
                    ans = max(ans, count[node] - count[neigh] + 1);
                }
            }
      
        
        dfsVis[node] = 0;
        
    }
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        
        vector<int> vis(n, 0), dfsVis(n, 0), count(n, 1);
        
        for(int i = 0 ; i < n; i++){
            if(!vis[i])
                dfs(i, edges, vis, dfsVis, count);
        }
        
        return ans;
        /*
        unordered_map<int,list<int> > adj;
        for(int i = 0 ; i < n; i++){
            int u = i;
            int v = edges[i];
            if(v != -1)
                adj[u].push_back(v);
        }
        
        // step1 cycle detect
        vector<int> in(n, 0);
        
        for(int i = 0; i < n; i++){
            if(edges[i] != -1)
                in[edges[i]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            // cout<<front<< " ";
            ans.push_back(front);
            
            for(auto neigh : adj[front]){
                in[neigh]--;
                if(in[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        if(ans.size() == n)
            return -1;
        return n - ans.size();
        */
        
        
        
        
    }
};