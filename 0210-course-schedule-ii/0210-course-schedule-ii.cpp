class Solution {
   
    
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,list<int> > adj;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        
         vector<int> in(n, 0);
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(auto neigh : adj[i])
	        {
	            in[neigh]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0;i < n; i++)
	    {
	        if(in[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto neigh : adj[node])
	        {
	            in[neigh]--;
	            if(in[neigh] == 0)
	                q.push(neigh);
	        }
	    }
	    
	    if(topo.size() == n) return topo;
	    return {};
	    
        
        
    }
};