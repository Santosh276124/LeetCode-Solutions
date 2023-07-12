class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        //step1 reverse edges of graph
        unordered_map<int,list<int>> adj;
        
        vector<int> outdegree(n);
        
        queue<int> q;
        
        for(int i = 0; i < graph.size(); i++){
            
            for(auto g : graph[i]){
                
                adj[g].push_back(i);
                
            }
            
            outdegree[i] = graph[i].size();
            
            if(outdegree[i] == 0)
                q.push(i);
        }
        
        
        vector<int> ans;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto neigh : adj[node]){
                
                outdegree[neigh]--;
                if( outdegree[neigh] == 0)
                    q.push(neigh);
                
            }
            
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};