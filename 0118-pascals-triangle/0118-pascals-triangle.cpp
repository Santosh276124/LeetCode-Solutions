class Solution {
public:
    long long NCR(long long n, long long r){
        
        // int res = 0;
        
        if(r == 0)
            return 1;
        
        else
            return (n-r+1) * NCR(n, r-1) / r;
        
        // return res;
        
    }
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        
        for(int i = 0; i < n; i++){
            
            ans[i].resize(i+1);
            
            for(int j = 0; j <= i; j++){
                
                int val = NCR(i, j);
                
                ans[i][j] = val;
                
            }
            
        }
        
        long long ncr = NCR(0, 0);
        cout<<ncr<<" ";
        
        
        return ans;
        
    }
};