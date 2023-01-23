class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.size() == 0 && n == 1) return n;
        
        unordered_map<int,vector<int> > adj;
        
        for(int i = 0; i < trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];
            
            adj[v].push_back(u);
        }
        

        
        vector<bool> vis(n);
        
        for(auto m : adj)
        {
            for(auto j : m.second)
            {
                vis[j] = true;
            }
        }
        
        
            for(auto child : adj){
          
            // cout<<child.first<<" ";
            // vector<int> temp = child.second;
            if(child.second.size() == n-1 &&vis[child.first] == false )
            {
                return child.first;
            }
            // else return -1;
            
        }
            
        return -1;
        
    }
};