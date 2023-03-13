//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        unordered_map<int,list<pair<int,int>> > adj;
        
        for(int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        vector<int> dist(n, 1e9);
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        pq.push({0, {src, 0}});  // stops, node, dist
        
        dist[src] = 0;
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int stops = top.first;
            int node = top.second.first;
            int nodeDist = top.second.second;
     
         
            if(stops > K)
                break;
            
            for(auto neigh : adj[node])
            {
                int neighNode = neigh.first;
                int neighDist = neigh.second;
                
                if(nodeDist + neighDist < dist[neighNode])
                {
                    dist[neighNode] = nodeDist + neighDist;
                    
                    pq.push({stops+1, {neighNode, dist[neighNode]}});
                }
            }
        }
        
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends