class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        unordered_map<int, list<pair<int,int>> > adj;
        
        for(int i = 0; i < points.size(); i++)
        {
            int  x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j = i+1; j < points.size(); j++)
            {
                int  x2 = points[j][0];
                int y2 = points[j][1]; 
                
                int cost = abs(x2-x1) + abs(y2-y1);
                
                adj[i].push_back({j, cost});
                adj[j].push_back({i, cost});
            } 
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> vis(n, 0);
        
        pq.push({0, 0}); //wt, node
        
        int sum = 0;
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int wt = top.first;
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            
            sum += wt;
            
            for(auto neigh : adj[node])
            {
                int neighNode = neigh.first;
                int neighWt = neigh.second;
                
                if(!vis[neighNode])
                {
                    pq.push({neighWt, neighNode});
                }
            }
        }
        
        return sum;
        
        
        
    }
};