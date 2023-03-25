class DisjointSet {
  public:
    vector<int> parent, size, rank;
    DisjointSet(int V){
        parent.resize(V+1);
        rank.resize(V+1, 0);
        size.resize(V+1, 1);
        for(int i = 0; i <= V; i++){
            parent[i] = i;
        }
    }
    
    int findPar(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        
        if(ult_u == ult_v) return;
        
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } 
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        DisjointSet ds(n);
        
        vector<int> temp;
        long long totalSum = 0;
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            if(ds.findPar(u) == ds.findPar(v))
                continue;
            else
                ds.unionBySize(u, v);
        }
        
        
        
        for(int i = 0; i < n; i++){
            
            cout<< ds.parent[i] <<" ";
            
            if(ds.parent[i] == i){
                totalSum += ds.size[i];
                temp.push_back(ds.size[i]);
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < temp.size(); i++){
            ans += (temp[i] * (totalSum - temp[i]));
            
            totalSum -= temp[i];
        }
        
        return ans;
        
    }
};