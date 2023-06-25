class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans;
        
        priority_queue<pair<int,int>> pq;
        
        int j = 0;
        
        for(int i = 0; i < n; i++){
            
            while(i-j+1 <= k){
                pq.push({nums[i], i});
                i++;
            }
            
            i--;
            
            ans.push_back(pq.top().first);
            
            while(!pq.empty() && pq.top().second <= j){
                pq.pop();
            }
            
          
            j++;
            
        }
        
        return ans;
        
    }
};