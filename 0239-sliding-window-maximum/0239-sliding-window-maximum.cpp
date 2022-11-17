class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         priority_queue<pair<int,int>> pq;  //element, index;
//         vector<int> ans;
//         int n = nums.size();
        
//         for(int i = 0; i < k; i++)
//             pq.push({nums[i], i});
        
//         ans.push_back(pq.top().first);
        
//         for(int i = k; i < n; i++)
//         {
//             pq.push({nums[i], i});
            
//                 while(pq.top().second <= (i-k))
//                     pq.pop();
        
//             ans.push_back(pq.top().first);
//         }
        
//         return ans;
        
        
         deque<int> dq;
       vector<int> ans;
       int i = 0;
       int j = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            while(dq.size() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);

            
             if(i-j+1 == k)
            {
               ans.push_back(dq.front());
                
                if(dq.front() == nums[j])
                {
                    dq.pop_front();
                }
                
                j++;
            }
            
           
        }
        return ans;
        
    }
};