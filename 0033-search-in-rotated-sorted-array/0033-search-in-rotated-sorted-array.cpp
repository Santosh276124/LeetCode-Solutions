class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<pair<int,int>> arr;
        
        for(int i =0; i <n; i++)
            arr.push_back({nums[i], i});
        
        sort(arr.begin(), arr.end());
        
        int l = 0;
        int h = n-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            
            if(arr[m].first == target)
                return arr[m].second;
            
            else if(arr[m].first > target)
                h = m-1;
            else
                l = m+1;
        }
        
        return -1;
        
    }
};