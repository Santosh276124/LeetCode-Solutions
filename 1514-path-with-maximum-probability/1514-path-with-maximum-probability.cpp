class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        
        unordered_map<int,list<pair<int,double>> > adj;
        
        for(int i =0; i < edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
       
        vector<double> prob(n, 0.0);
        
        queue<pair<int,double>> q;
        
     
        q.push({start, 1.0});
        // vis[start] = 1;
        
        while(!q.empty()){
            auto top = q.front();
            
            q.pop();
            int node = top.first;
            double nodeDist = top.second;
            
          
            for(auto neigh : adj[node]){
                int neighNode = neigh.first;
                double neighDist = neigh.second;
                if( nodeDist*neighDist > prob[neighNode] ){
                    
                    prob[neighNode] = nodeDist*neighDist;
                    
                    q.push({neighNode, prob[neighNode]});
                }
            }
            
        }
        
        
        return prob[end];
        
    }
};