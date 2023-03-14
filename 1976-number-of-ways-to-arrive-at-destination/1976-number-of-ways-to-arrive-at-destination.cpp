class Solution {
public:
  
    int mod = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long long,long long>> adj[n];
        
        for(int i = 0; i< roads.size(); i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long w = roads[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<long long> dist(n, 1e18);
        
        vector<long long> ways(n, 0);
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        
        pq.push({0, 0});
        
        dist[0] = 0;
        
        ways[0] = 1;
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            long long node = top.second;
            long long nodeDist = top.first;
            for(auto neigh : adj[node])
            {
                if(nodeDist + neigh.second < dist[neigh.first])
                {
                    dist[neigh.first] = nodeDist + neigh.second;
                    
                    ways[neigh.first] = (ways[node])%mod;
                    
                    pq.push({dist[neigh.first], neigh.first});
                }
                else if(nodeDist + neigh.second == dist[neigh.first])
                {
                    ways[neigh.first] = (ways[neigh.first] + ways[node])%mod;
                }
            }
        }
        
     
        return ways[n-1]%mod;
        
    }
};