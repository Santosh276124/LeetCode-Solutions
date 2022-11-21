class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }
         
        if(n == k) return totalSum;
        int j = 0;
        int minSum = totalSum;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(i-j+1 == n-k)
            {
                minSum = min(minSum, sum);
                sum -= nums[j];
                j++;
            }
        }
       
     
        
        return totalSum-minSum;
    }
};