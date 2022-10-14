class Solution {
public:
    int trap(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> prefMax(n);
        vector<int> suffMax(n);
        
        int maxi = heights[0];
        for(int i = 0; i < n; i++)
        {
            if(heights[i] >= maxi)
            {
                maxi = heights[i];
                
            }
            prefMax[i] =maxi;
            
            // cout<<prefMax[i]<<" ";
        }
        int rightMax = heights[n-1];
        for(int i = n-1; i>= 0; i--)
        {
            if(heights[i] >= rightMax)
                rightMax = heights[i];
            
            suffMax[i] = rightMax;
            
        }
       
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += (min(prefMax[i], suffMax[i]) - heights[i]);
        }
        
        return res;
    }
};