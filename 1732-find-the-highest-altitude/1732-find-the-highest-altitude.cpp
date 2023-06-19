class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        
        int maxi = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            prev += gain[i];
            maxi = max(maxi, prev);
        }
        
        return maxi;
    }
};