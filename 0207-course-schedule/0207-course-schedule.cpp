class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        int n = pre.size();
        
        unordered_map<int,list<int>> adj;
        vector<int> indegree(numCourses);
        
        for(int i=0; i < n; i++){
            
           int u = pre[i][0];
            int v= pre[i][1];
            
            adj[u].push_back(v);
            
        }
        
        for(int i = 0; i < numCourses; i++){
            for(auto neigh : adj[i])
            {
                indegree[neigh]++;
            }  
        }
        
        queue<int> q;
        
        for(int i= 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // vector<int> ans;
        int cnt = 0;
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            // ans.push_back(node);
            cnt++;
            for(auto neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        if(cnt == numCourses) return true;
        return false;
        
    }
};