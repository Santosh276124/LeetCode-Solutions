class Solution {
    void dfs(int node, int parent, unordered_map<int,list<int>>& adj, string &labels, vector<int> &count, vector<int> &ans)
    {
       
        int before_visiting_current_node_label_count = count[labels[node]-'a'];
        
        count[labels[node]-'a']++;
        
        for(auto child : adj[node])
        {
            if(child == parent) continue;
            
            dfs(child, node, adj, labels, count, ans);
            
        }
        
         int after_visiting_current_node_label_count = count[labels[node]-'a'];
        
        //update ans for current node
        ans[node] = after_visiting_current_node_label_count - before_visiting_current_node_label_count;
        
        return;
        
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        unordered_map<int,list<int>>adj;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        vector<int> count(26, 0);
        
        dfs(0, -1, adj, labels, count, ans);
        
        return ans;
    }
};