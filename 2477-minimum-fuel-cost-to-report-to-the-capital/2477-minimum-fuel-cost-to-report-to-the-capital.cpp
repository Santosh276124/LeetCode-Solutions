class Solution {
public:
    int dfs(unordered_map<int,list<int>>& graph, int u, int prev, int seats,
          long long& ans) {
    int people = 1;
    for ( auto v : graph[u]) {
      if (v == prev)
        continue;
      people += dfs(graph, v, u, seats, ans);
    }
    if (u > 0)
      // # of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
  }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        long long ans = 0;
    // vector<vector<int>> graph(roads.size() + 1);
        unordered_map<int,list<int>> graph;

    for (auto road : roads) {
       int u = road[0];
       int v = road[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, -1, seats, ans);
    return ans;
    }
};