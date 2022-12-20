class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        unordered_map<int,list<int>> adj;
        int n = rooms.size();
        for(int i = 0; i < rooms.size(); i++)
        {
            for(auto j : rooms[i])
            {
                adj[i].push_back(j);
            }
        }
        
        vector<bool> vis(n, false);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            
            for(auto neigh : adj[top])
            {
                if(vis[neigh] == false)
                {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == false) return false;
        }
        return true;
    }
};