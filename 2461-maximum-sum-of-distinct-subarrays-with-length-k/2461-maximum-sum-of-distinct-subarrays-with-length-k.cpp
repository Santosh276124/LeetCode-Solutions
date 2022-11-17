class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        
        
        
        long long i = 0, n = v.size(), j = 0;
        long long ans = INT_MIN ,sum = 0;
        unordered_map<long long,long long>mp;
        for(int j = 0; j < n; j++) {
            mp[v[j]]++;
            sum += v[j];
           
             if(j - i + 1 == k) {
                    if(mp.size() == k) {
                        ans = max(ans, sum);
                    }
                    mp[v[i]]--;
                    if(mp[v[i]] == 0)
                        mp.erase(v[i]);
                    sum -= v[i];
                    i++;
                   
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};