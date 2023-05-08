class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int col = mat[0].size();
        
        int i;
        int j;
        
        //primary diagonal:
        int sum1 = 0;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < col; j++)
            {
                if( i == j)
                {
                    sum1 = sum1 + mat[i][j];
                }
            }
        }
        
        
        //secodary diagonal sum::
        
        int sum2 = 0;
        int k = col-1;
        for(i = 0; i < rows; i++)
        {
            for(j = k; j >= 0; )
            {
                if(i!=j)
                {
                    
                sum2 = sum2 + mat[i][j];
                    
                }
                break;
            }
            k--;
        }
        
        
        
        return (sum1 + sum2) ;
        
    }
};