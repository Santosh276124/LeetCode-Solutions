class Solution {
   
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // unordered_map<int,list<int>> adj;
        
        int n = graph.size();
//         for(int i = 0; i < graph.size(); i++)
//         {
//             int u = graph[i][0];
//             int v = graph[i][1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
        vector<int> color(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(color[i] != 0) continue;
            
           
            q.push(i);
            color[i] = 1;
            while(!q.empty())
            {
                auto node = q.front();
                q.pop();
                for(auto neigh : graph[node])
                {
                    if(color[neigh] == color[node])
                        return false;

                    if(color[neigh] == 0)
                    {
                        color[neigh] = -color[node];
                        q.push(neigh);
                    }
                }
            }

        }
        return true;
    }
};