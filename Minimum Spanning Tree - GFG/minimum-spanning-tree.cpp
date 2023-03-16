//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> parent, rank;
public:
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here  
        
        /*
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> vis(V, 0);
        
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
                int neighNode = neigh[0];
                int neighWt = neigh[1];
                
                if(!vis[neighNode])
                {
                    pq.push({neighWt, neighNode});
                }
            }
        }
        
        */
        
        
        //kruskals algo
        
        vector<pair<int,pair<int,int>>> adjj;  //wt -> u, v
        
        for(int i = 0; i < V; i++)
        {
            for(auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                adjj.push_back({wt, {u, v}});
            }
        }
        
        //step2
        sort(adjj.begin(), adjj.end());  //acc to wt
        
        //step3
        DisjointSet ds(V);
        
        //step4
        int sum = 0;
        for(auto neigh : adjj)
        {
            int wt = neigh.first;
            int u = neigh.second.first;
            int v = neigh.second.second;
            
            if(ds.findParent(u) != ds.findParent(v))
            {
                sum += wt;
                
                ds.unionByRank(u, v);
            }
        }
        
        
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends