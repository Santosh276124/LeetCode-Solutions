class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int d = arr[1] - arr[0];
        
        for(int i = 2; i < n; i++){
            if(d != (arr[i]-arr[i-1]))
                return false;
        }
        
        return true;
    }
};