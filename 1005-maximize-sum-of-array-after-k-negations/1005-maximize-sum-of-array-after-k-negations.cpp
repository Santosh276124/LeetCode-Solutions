class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
       
        priority_queue<int, vector<int>, greater<int>> q;
        
        
        for(auto num : nums)
            q.push(num);
        
        while(k--)
        {
            int x = q.top();
            q.pop();
            q.push(-1*x);
        }
        int sum = 0;
        while(!q.empty())
        {
            sum += q.top();
            q.pop();
        }
        return sum;
        
//         int sum = 0;
        
//         while(k>0)
//         {
//             if(!q.empty() && q.top() < 0) 
//             {
//                 sum += abs(q.top());
//                 q.pop();
//                 k--;
//             }
            
//             else if(q.top() == 0){
//                 k--;
//                 break;
//             }
            
//             else if(q.top() > 0) {
//                 if(k%2 == 0)
//                 {
//                      sum += q.top();
//                      q.pop();
//                     k--;
//                     break;
//                 }
//                 else
//                 {
//                     sum += (-q.top());
//                     q.pop();
//                     k--;
//                     break;
//                 }
                
//             }
            
//         }
//         while(!q.empty())
//         {
//             sum += q.top();
//             q.pop();
//         }
//         return sum;
    }
};