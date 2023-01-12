class Solution {
    vector<int> dfs(int node, int parent, unordered_map<int,list<int>>& adj, string &labels, vector<int> &ans)
    {
        vector<int> myCount(26, 0);
        char myLabel = labels[node];
        myCount[myLabel-'a'] = 1;
        
        for(auto child : adj[node])
        {
            if(child == parent) continue;
            
            vector<int> childCount = dfs(child, node, adj, labels, ans);
            
            for(int i = 0; i < 26; i++)
            {
                myCount[i] += childCount[i];
            }
        }
        
        //update ans for current node
        ans[node] = myCount[myLabel-'a'];
        
        return myCount;
        
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
        
        dfs(0, -1, adj, labels, ans);
        
        return ans;
    }
};