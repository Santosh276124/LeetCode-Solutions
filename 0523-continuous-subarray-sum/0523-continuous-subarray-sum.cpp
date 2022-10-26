class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int sum =0;
        int n = nums.size();
        unordered_map<int,int> prevSum;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            sum%=k;
            
            if(sum == 0 && i != 0)
            {
                return true;
            }
            
            if(prevSum.find(sum) != prevSum.end() )
            {
                if( i - prevSum[sum] > 1)
                {
                    return true;
                }
            }
            
            else
              prevSum[sum] = i;
           
        }
        return false;
    }
};