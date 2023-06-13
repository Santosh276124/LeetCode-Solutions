class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int curr = 0;
   
        int cnt = 0;
        
        unordered_map<int,int> prefSum;
        
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            
            if(curr == k)
                cnt++;
            
            if(prefSum.count(curr-k))
                cnt += prefSum[curr-k];
            
            prefSum[curr]++;
            
            
        }
        
        return cnt;
        
    }
};