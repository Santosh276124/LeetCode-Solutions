class Solution {
public:
    vector<vector<int>> adjList;
    vector<bool> visited;
    
    // returned value: rode length from root to and only to ALL apples which can be found beyond and include node
    int dfs(int node,vector<bool>& hasApple,int d){
        visited[node]=true;
        int result=d;	//Initialize result as d.        
        for(auto &child:adjList[node])
            if(!visited[child]) {
                int dist2apple=dfs(child,hasApple,d+1); //rode distance between root to ALL apples  beyound node 'child'
                if(dist2apple)  //If child has apples it'll return a non zero result which is the distance traveled upto that node.
                    result+=dist2apple-d;                     
            }
        
        return (hasApple[node]   // current 'node' has apple
                ||               // or  
                result > d) ?    // offspring(s) of current 'node' have apple(s)
                result: 0;       // if true, we count the road length, otherwise, no road is needed.
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        adjList.resize(n);
        visited.resize(n,false);
        for(auto& e:edges)
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
        return dfs(0,hasApple,0)*2; 
    }
};