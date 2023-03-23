class DisJointset{
  public:
    vector<int> parent, rank, size;
    
    DisJointset(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
        
        int findParent(int node){
            if(node == parent[node])
                return node;
            
            return parent[node] = findParent(parent[node]);
        }
        
        void unionByRank(int u, int v){
            
            int ult_u = findParent(u);
            int ult_v = findParent(v);
            
            if(ult_u == ult_v) return;
            
            if(rank[ult_u] < rank[ult_v]){
                parent[ult_u] = ult_v;
            }
            else if(rank[ult_u] > rank[ult_v]){
                parent[ult_v] = ult_u;
            }
            else{
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
         }
        
        void unionBySize(int u, int v){
            int ult_u = findParent(u);
            int ult_v = findParent(v);
            
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisJointset ds(n);
        
        //find extra edge
        int extra = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u) == ds.findParent(v)){
                extra++;
            }
            else{
                ds.unionByRank(u, v);
            }
        }
        
        //find connected comp
        int comp = 0;
        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i)
                comp++;
        }
        
        int ans = comp-1;  //need atleast this edge
        
        return extra >= ans ? ans : -1;
        
    }
};