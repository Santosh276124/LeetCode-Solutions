class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(auto el : nums)
            pq.push(el);
        
        int ans = 0;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};