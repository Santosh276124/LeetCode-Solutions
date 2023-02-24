class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        //perform one operation first
        for(int i = 0;  i < nums.size(); i++)
        {
            if(nums[i]%2 != 0)
                nums[i]*=2;
            
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        int minDev = maxi-mini;
        
        priority_queue<int> pq;
        
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        while((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop();
            
            minDev = min(minDev, top-mini);
            
            top /= 2;
            
            mini = min(mini, top);
            
            pq.push(top);
        }
        
        minDev = min(minDev, pq.top()-mini);
        
        return minDev;
        
    }
};