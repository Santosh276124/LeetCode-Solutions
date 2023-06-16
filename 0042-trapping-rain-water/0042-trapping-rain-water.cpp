class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, height[i]);
            pref[i] = maxi;
        }
        
        maxi = INT_MIN;
        
        for(int i = n-1; i >= 0; i--){
            maxi = max(maxi, height[i]);
            suff[i] = maxi;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (min(pref[i], suff[i]) - height[i]);
        }
        
        return ans;
        
    }
};