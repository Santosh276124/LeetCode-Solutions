class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
            // cout<<tasks[i]<<" ";
        }
        
        sort(tasks.begin(), tasks.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq;
        
        int ind = 0;
        long long currTime = tasks[ind][0];
        
        vector<int> ans;
        
        while(ind < n || !pq.empty())
        {
//             if(pq.empty() && ind < n)
//             {
                
//             }
            
            
            while(ind < n && tasks[ind][0] <= currTime)
            {
                pq.push({tasks[ind][1], tasks[ind][2]});
                ind++;
            }
            
            if(pq.empty())
            {
                currTime = tasks[ind][0];
            }
           else
           {
                pair<int,int> el = pq.top();
                pq.pop();

                currTime += el.first;

                ans.push_back(el.second);
           }
        }
        
        return ans;
    }
};