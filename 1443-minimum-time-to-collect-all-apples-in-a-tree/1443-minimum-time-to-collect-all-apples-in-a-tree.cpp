class Solution {
public:
     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>graph(n);
        unordered_set<int>v;
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        v.insert(0);
        return dfs(graph, v, hasApple, 0);
    }
    int dfs(vector<vector<int>>& graph, unordered_set<int>& v, vector<bool>& has, int cur)
    {
        int res = 0;
        for(auto a:graph[cur])
        {
            if(v.count(a))continue;
            v.insert(a);
            res += dfs(graph, v, has, a);
        }
        if((res > 0 || has[cur]) && cur != 0)res += 2;
        return res;
        
    }
};