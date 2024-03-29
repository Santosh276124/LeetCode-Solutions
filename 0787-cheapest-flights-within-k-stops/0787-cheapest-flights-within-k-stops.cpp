class Solution
{
    
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {

            unordered_map<int, list<pair<int, int>>> adj;

            for (int i = 0; i < flights.size(); i++)
            {
                int u = flights[i][0];
                int v = flights[i][1];
                int w = flights[i][2];

                adj[u].push_back({ v, w });
            }
            
           
            queue< pair<int,pair<int,int>> > pq;
            
            pq.push({0, {src, 0}}); //stop, node, dist
            
            vector<int> dist(n, 1e9);
            dist[src] = 0;
            
            while(!pq.empty())
            {
                auto top = pq.front();
                pq.pop();
                
                int stops = top.first;
                int node = top.second.first;
                int nodeDist = top.second.second;
                
                if(stops > k) continue;
                
                for(auto child : adj[node])
                {
                    int childNode = child.first;
                    int childDist = child.second;
                    
                    if(nodeDist + childDist < dist[childNode] && stops <= k)
                    {
                        dist[childNode] = nodeDist + childDist;
                        
                        pq.push( { stops+1, {childNode, dist[childNode]} } );
                    }
                }
            }
            
            
          return dist[dst] == 1e9 ? -1 : dist[dst];
        }
};