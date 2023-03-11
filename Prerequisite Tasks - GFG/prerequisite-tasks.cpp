//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, unordered_map<int,list<int>>& adj,vector<int>& vis, vector<int>& pathVis )
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto neigh : adj[node])
        {
            if(!vis[neigh])
            {
                if(dfs(neigh, adj, vis, pathVis)) return true;
            }
            else if(pathVis[neigh])
                return true;
        }
        
        pathVis[node] = 0;
        
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    unordered_map<int,list<int>> adj;
	    
	    for(int i = 0; i < prerequisites.size(); i++)
	    {
	        int u = prerequisites[i].first;
	        int v = prerequisites[i].second;
	        
	        adj[u].push_back(v);
	    }
	    
	    vector<int> vis(N, 0);
	    vector<int> pathVis(N, 0);
	    
	    for(int i = 0; i < N; i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i, adj, vis, pathVis)) //cycle present
	                return false;
	        }
	    }
	    
	    return true;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends