class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int currSum= 0;
        int  cnt = 0;
        
        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            
            int remainder = (currSum % k + k) % k;
            if(remainder == 0) cnt++;
            
             if(mp.count(remainder) )
                cnt += mp[remainder];
            
            mp[remainder]++;
        }
        
        return cnt;
        
    }
};