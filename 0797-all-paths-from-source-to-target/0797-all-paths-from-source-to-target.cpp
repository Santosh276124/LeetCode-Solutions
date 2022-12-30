class Solution {
    vector<vector<int>> ans;
    
    void dfs(int node, int tar, vector<int> &temp, vector<vector<int>>& graph)
    {
        temp.push_back(node);
        
        if(node == tar)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto neigh : graph[node])
        {
            dfs(neigh, tar, temp, graph);
            temp.pop_back();
        }   
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int tar = n-1;
        vector<int> temp;
        dfs(0, tar, temp, graph);

        return ans;
    }
};