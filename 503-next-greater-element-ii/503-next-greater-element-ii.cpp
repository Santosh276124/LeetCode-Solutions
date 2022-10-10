class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> s;
        vector<int> ans;
        for(int i = n-1; i>= 0; i--)
            s.push(nums[i]);
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && nums[i] >= s.top())
                s.pop();
            
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
            
            s.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};