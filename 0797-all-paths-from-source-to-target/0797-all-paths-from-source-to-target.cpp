class Solution {
    vector<vector<int>> ans;
    
    void dfs(int node, int tar, unordered_map<int,vector<int> >&adj, vector<bool> &vis, vector<int> &temp)
    {
        if(node == tar)
        {
            ans.push_back(temp);
            return;
        }
        
        if(!vis[node])
            temp.push_back(node);
        
        vis[node] = true;
        
        for(auto neigh : adj[node])
        {
            if(!vis[neigh])
            {
                vis[neigh] = true;
                temp.push_back(neigh);
                
                dfs(neigh, tar, adj, vis, temp);
                
                vis[neigh] = false;
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int> > adj;
        
        for(int i = 0; i < graph.size(); i++)
        {
            vector<int> u = graph[i];
            
            adj[i] = u;
        }
        
        int source = 0;
        int tar = n-1;
        
        vector<bool> vis(n, false);
        vector<int> temp;
        dfs(0, tar, adj, vis, temp);
        
        
        
        return ans;
    }
};