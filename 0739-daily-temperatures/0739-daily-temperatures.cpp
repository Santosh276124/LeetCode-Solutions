class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int,int> > s; // pair<element, index>
       
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && temp[i] >= s.top().first)
            {
                s.pop();
               
                
            }
            if(!s.empty())
              ans[i] = s.top().second - i;
                
            s.push({temp[i],i});
        }
        return ans;
    }
};