class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<pair<int,int>> st;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    st.insert({i, j});
                }
            }
        }
        
        for(auto s : st){
            // cout<<m<<" ";
            int r = s.first;
            int c = s.second;
            
            cout<<r <<" "<< c<<" ";
            
            //row to 0
            for(int i = 0; i < m; i++){
                matrix[r][i] = 0;
            }
            //column to 0
            for(int i = 0; i < n; i++){
                matrix[i][c] = 0;
            }
        }
        
        return ;
        
    }
};