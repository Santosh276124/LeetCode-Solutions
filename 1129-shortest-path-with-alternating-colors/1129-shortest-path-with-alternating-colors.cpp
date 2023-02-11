class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int,list<pair<int,int>> > adj;
        
        for(int i = 0; i < redEdges.size(); i++)
        {
            int  u = redEdges[i][0];
            int v = redEdges[i][1];
            
            adj[u].push_back({v, 1});
        }
        for(int i = 0; i < blueEdges.size(); i++)
        {
            int  u = blueEdges[i][0];
            int v = blueEdges[i][1];
            
            adj[u].push_back({v, 2});
        }
        
        int prevC;  //-2 for red and -3 for blue  -1 for none
        
        queue<pair<int, pair<int,int>> >pq;
        // priority_queue< pair<int, pair<int,int>>, vector<pair<int,
        // pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
        
        // vector<int> dist(n, 1e9);
        vector<vector<int>> dist(n, vector<int>(3, 1e9));
        dist[0][0] = 0;
        
        pq.push({0, {0, 0}});  //dist, <node, prevC>
        
        while(!pq.empty())
        {
            auto top = pq.front();
            pq.pop();
            
            int topNode = top.second.first;
            int nodeDist = top.first;
            prevC = top.second.second;
            
            for(auto neigh : adj[topNode])
            {
                int neighNode = neigh.first;
                int wt = 1;
                int neighC = neigh.second;
                
                if((neighC != prevC) && nodeDist + wt < dist[neighNode][neighC])
                {
                    dist[neighNode][neighC] = nodeDist + wt;
                    
                    pq.push({dist[neighNode][neighC], {neighNode, neighC}});
                }
            }
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
        {
           int dis = min(dist[i][0], min(dist[i][1], dist[i][2]));
        
           ans[i] =  dis == 1e9 ? -1 : dis;
        }
        return ans;
        
    }
};