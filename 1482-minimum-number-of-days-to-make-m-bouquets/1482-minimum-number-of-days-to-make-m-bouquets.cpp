class Solution {
    bool isFeasible(vector<int>& nums, int mid, int m, int k)
    {
        int n = nums.size();
         
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= mid)
            {
                cnt++;
            }
            else
                cnt = 0;
            
            if(cnt == k){
                ans++;
                cnt = 0;
            }
            
            
        }
      
       
       if(ans >= m) return true;
         return false; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
     
        
      
        int s = 1;
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(s < e)
        {
            int mid = s+(e-s)/2;
            if(isFeasible(bloomDay, mid, m, k))
                e = mid;
            else
                s = mid+1;
        }
        if(isFeasible(bloomDay, s, m, k))
         return s;
        return -1;
        
    }
};