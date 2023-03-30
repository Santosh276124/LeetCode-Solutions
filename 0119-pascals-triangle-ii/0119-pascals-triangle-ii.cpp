class Solution {
public:
    vector<int> getRow(int n) {
        
        vector<int> ans(n+1, 1);
        long long int temp = 1;  //nC0
        
        for(int r = 1; r < n; r++){
            
            temp = temp * (n-r+1)/r;  //nCr
            
            ans[r] = temp;
        }
        
        return ans;
        
    }
};