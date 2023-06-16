class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++){
            int tar = 0-nums[i];
            
            int s = i+1;
            int e = n-1;
            
            while(s < e){
                long long sum = nums[s] + nums[e];
                if(sum == tar)
                {
                    vector<int> temp = {nums[i], nums[s], nums[e]};
                    // sort(temp.begin(), temp.end());
                    st.insert(temp);
                    s++;
                    e--;
                }
                else if(sum < tar)
                    s++;
                else
                    e--;
                    
            }
            
            
        }
        
        vector<vector<int>> ans;
        
        for(auto s : st)
            ans.push_back(s);
        
        return ans;
        
    }
};