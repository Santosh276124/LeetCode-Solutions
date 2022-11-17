class Solution {
    int atMost(vector<int>&nums, int k)
    {
        unordered_map<int,int> m;
        int j = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
            
            while(m.size() > k)
            {
                m[nums[j]]--;
                if(m[nums[j]] == 0)
                    m.erase(nums[j]);
                j++;
            }
            
            ans += (i-j+1);
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
       return atMost(nums, k) - atMost(nums, k-1);
    }
};