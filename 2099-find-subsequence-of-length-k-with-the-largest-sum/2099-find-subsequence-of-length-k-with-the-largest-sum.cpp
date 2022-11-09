class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        for(int i = 0; i < nums.size();i++)
            q.push({nums[i], i});
        
       
        while(q.size() > k)
        {
            
            q.pop();
        }
        
        map<int,int> m;
        while(!q.empty())
        {
            auto x = q.top();
            q.pop();
            m[x.second] = x.first;
        }
       
        vector<int> ans;
 
        for(auto j : m)
        {
            ans.push_back(j.second);
        }
        return ans;
        
    }
};