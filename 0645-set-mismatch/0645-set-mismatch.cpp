class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> ans;
        set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        
        int currSum = 0;
        for(auto i : s) currSum += i;
        
        int totalSum = n*(n+1)/2;
        
        int missing = totalSum - currSum;
        
        
        
        unordered_map<int,bool> m;
        for(int i = 0; i < n; i++)
        {
            if(m[nums[i]] == true) 
            {
                ans.push_back(nums[i]);
                break;
            }
                
            
            m[nums[i]] = true;
        }
        
        ans.push_back(missing);
        return ans;
        
    }
};