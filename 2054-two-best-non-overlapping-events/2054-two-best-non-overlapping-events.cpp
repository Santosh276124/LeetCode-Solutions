class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        
        int ans = 0;
        int maxVal = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        sort(events.begin(), events.end());
        
        for(auto e : events)
        {
            while(!pq.empty() && pq.top().first < e[0])
            {
                maxVal = max(maxVal , pq.top().second);
                pq.pop();
            }
            
            ans = max(ans, maxVal+e[2]);
            pq.push({e[1], e[2]});
        }
        return ans;
        
    }
};