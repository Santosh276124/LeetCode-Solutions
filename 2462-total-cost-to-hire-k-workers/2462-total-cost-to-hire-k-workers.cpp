class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        
        long long ans = 0;
        int n = costs.size();
        
        if(n == k){
            for(auto el : costs)
                ans += el;
            
            return ans;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq1, pq2;
        
        
        int i = 0;
        
        for(; i < c; i++){
            pq1.push({costs[i], i});
        }
        
        // i = c;
        
        int j = n-1;
        for(; j >= max(i, n-c); j--){
            pq2.push({costs[j], j});
        }
        
        // j = n-c-1;
        
        while(k > 0){
            
            //1
            if(!pq1.empty() && !pq2.empty()){
                auto top1 = pq1.top();
                auto top2 = pq2.top();

                 if(top1.first <= top2.first){
                    ans += top1.first;
                    pq1.pop();
                    if(i <= j){
                            pq1.push({costs[i], i});
                            i++;
                        }
                }
                else{
                    ans += top2.first;
                    pq2.pop();
                    if(j >= i){
                            pq2.push({costs[j], j});
                            j--;
                        }
                }
            }
            
            //2
            else if(!pq1.empty()){
                auto top1 = pq1.top();
                 ans += top1.first;
                    pq1.pop();
                    if(i <= j){
                            pq1.push({costs[i], i});
                            i++;
                    }
            }
            
            //3
            else if(!pq2.empty()){
                auto top2 = pq2.top();
                 ans += top2.first;
                    pq2.pop();
                    if(j >= i){
                            pq2.push({costs[j], j});
                            j--;
                    }
            }
            
           
            k--;
            
            
        }
        
        
        // cout<<i<<" "<<j<<" "<<k<<" ";
        
        return ans;
        
        
    }
};