class Solution {
public:
    int n;
//     int solve(int ind, int prev, vector<int>&arr, int d, map<string,int>& mp){
        
//         if(ind < 0) return 0;
        
//         string key = to_string(ind) + "->" + to_string(prev);
        
        
//         if(mp.count(key)) return mp[key];
        
//        int take = 0;
//         int nottake = 0;
//         if(prev == INT_MIN || arr[ind] == prev-d){
//             take =  max(1 + solve(ind-1, arr[ind], arr, d, mp), solve(ind-1, prev, arr, d, mp));
//         }
//         else
//             nottake =  solve(ind-1, prev, arr, d, mp);
        
//         return mp[key] = max(take, nottake);
        
//     }
    int longestSubsequence(vector<int>& arr, int d) {
        
        n = arr.size();

        
        map<int,int> mp;
        
        // return solve(n-1, INT_MIN, arr, difference, mp);
        
        int maxi = 1;
        
        for(int i = 0; i < n; i++){
            
            int prev = arr[i] - d;
            
            int curr = 1;
            if(mp.count(prev)){
                curr += mp[prev];
            }
            
            mp[arr[i]] = curr;
            
            maxi = max(maxi, curr);
            
        }
        
       return maxi; 
        
        
        
        
        
        
    }
};