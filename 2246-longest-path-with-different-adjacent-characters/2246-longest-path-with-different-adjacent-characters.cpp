class Solution {
public:
    int maxLen;
    
    int dfs(int node, int parent, unordered_map<int,list<int>>& adj, string &s)
    {
        int longest = 0;
        int second_longest = 0;
        
        for(auto child : adj[node])
        {
            if(child == parent) continue;
            
            int child_longest_path = dfs(child, node, adj, s);
            
            if(s[child] == s[node]) continue;
            
            if(child_longest_path > second_longest)
                second_longest = child_longest_path;
            
            if(second_longest > longest)
                swap(longest, second_longest);
        }
        
        int neeche_hi_answer_mil_gya = 1 + longest + second_longest;
        
        // int koi_ek_acha = 1 + max(longest, second_longest);
        int koi_ek_acha = 1 + longest;
        
        // int sirf_root_acha = 1;
        
        maxLen = max({maxLen, neeche_hi_answer_mil_gya, koi_ek_acha});
        
        return koi_ek_acha;
    }
    int longestPath(vector<int>& parent, string s) {
        
        maxLen = 0;
        unordered_map<int,list<int>> adj;
        
        for(int i = 1; i < parent.size(); i++)
        {
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, adj, s);
        
        return maxLen;
    }
};