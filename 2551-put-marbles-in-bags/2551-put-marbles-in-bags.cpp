class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
     
        int n = weights.size();
        
        vector<long long> temp;
        
        for(int i = 1; i < n; i++){
            temp.push_back(weights[i]+weights[i-1]);
        }
        
        long long maxi = 0;
        long long mini = 0;
        
        sort(temp.begin(), temp.end());
        
        int n1 = temp.size();
        
        k--;
        
        for(int i = 0; i < k; i++){
            // cout<<temp[i]<<" ";
            mini += temp[i];
            maxi += temp[n1-1-i];
        }
        
        // for(int i = n1-1; i > k; i--){
        //     maxi += temp[i];
        // }
        
        // cout<<maxi<<" "<<mini<<" ";
        
        return maxi-mini;
        
    }
};