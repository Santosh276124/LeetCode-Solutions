//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet {
    
public:
        vector<int> parent, rank;
        DisjointSet(int V){
            rank.resize(V+1);
            parent.resize(V+1);
            for(int i = 0; i <= V; i++)
            {
                rank[i] = 0;
                parent[i] = i;
            }
        }
        
        int findParent(int node){
            if(node == parent[node])
                return node;
                
            return parent[node] = findParent(parent[node]);
        }
        
        void unionByRank(int u, int v)
        {
            int ul_u = findParent(u);
            int ul_v = findParent(v);
            
            if(ul_u == ul_v) 
                return;
            
            if(rank[ul_u] < rank[ul_v])
            {
                parent[ul_u] = ul_v;
            }
            else if(rank[ul_u] > rank[ul_v]){
                parent[ul_v] = ul_u;
            }
            else{
                parent[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int maxR = 0;
        int maxC = 0;
        
        for(auto it : stones){
            maxR = max(maxR, it[0]);
            maxC = max(maxC, it[1]);
        }
        
        DisjointSet ds(maxR + maxC + 1);
        
        unordered_map<int,int> nodeInvolved;
        
        for(auto it : stones){
            
           int nodeR = it[0];
           
           int nodeC = it[1] + maxR + 1;
           
           ds.unionByRank(nodeR, nodeC);
           
           nodeInvolved[nodeR]++;
           nodeInvolved[nodeC]++;
           
            
        }
        
        
        int cnt = 0;
        
        for(auto it : nodeInvolved){
            
            if(ds.findParent(it.first) == it.first)
                cnt++;
        }
        
        
       return n-cnt; 
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends