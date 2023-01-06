class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        // sort(costs.begin(), costs.end());
        
        priority_queue<int,vector<int>, greater<int> > pq;
        
        for(int cost : costs)
            pq.push(cost);
        
        int cnt = 0;
        
//         for(int i = 0; i < costs.size(); i++)
//         {
//             if(costs[i] <= coins)
//             {
//                 cnt++;
//                 coins -= costs[i];
//             }
 
//         }
        
        while(!pq.empty() && coins > 0)
        {
            int top = pq.top();
            pq.pop();
            
            if(top <= coins)
            {
                cnt++;
                coins -= top;
            }
          
        }
        
        return cnt;
    }
};