class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i = 0; 
        int j = n-1;
        
        long long area = 0;
        while(i < j)
        {
            int base = j - i;
            int ht = min(height[i], height[j]);
            
            long long ar = base*ht;
            
            area = max(area, ar);
            
            if(height[i] <= height[j])
                i++;
            else
                j--;
        }
        
        return area;
    }
};