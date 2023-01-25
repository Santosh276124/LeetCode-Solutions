class Solution {
public:
    int n;
    void dfs(int node, vector<int> &edges, vector<int>& dist, vector<bool>& vis)
    {
        
        vis[node] = true;
        
        
        int child = edges[node];
       
        if( child != -1 && vis[child] == false){
     
            vis[child] = true;
            dist[child] = dist[node] + 1;
        
            dfs(child, edges, dist, vis);
        }
    }
    void bfs(int node, vector<int> &edges, vector<int>& dist, vector<bool>& vis )
    {
        queue<int> q;
        q.push(node);
        
        dist[node] = 0;
        vis[node] = true;
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            
            int child = edges[top];
            
            if(child != -1 && !vis[child])
            {
                vis[child] = true;
                dist[child] = 1 + dist[top];
                q.push(child);
            }
        }
        
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        n = edges.size();
        
        vector<int> dist1(n, 1e9);
        vector<int> dist2(n, 1e9);
        
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        // dfs(node1, edges, dist1, vis1);
        // dfs(node2, edges, dist2, vis2);
        
        bfs(node1, edges, dist1, vis1);
        bfs(node2, edges, dist2, vis2);
        
       
        int mini = 1e9;
        int ansNode = -1;
        for(int i = 0; i < n; i++)
        {
            // cout<<dist1[i]<<" "<<dist2[i]<<" ";
            
            int val = max(dist1[i], dist2[i]);
            
            if(val < mini)
            {
                mini = val;
                
                ansNode = i;
            }
            
        }
        
       return ansNode;
    }
};