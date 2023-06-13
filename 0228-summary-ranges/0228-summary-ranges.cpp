class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0)
            return {};
        
        vector<string> ans;
        
        // string temp = "";
        
        int j =0;
        int i = 0;
        
        for( i= 1; i < n; i++){
            
            if(nums[i] == nums[i-1] + 1){
                
            }
            else{
                
                if(i-j > 1){
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i-1]));
                }
                
                else{
                    ans.push_back(to_string(nums[i-1]));
                }
                
                j = i;
                
            }
            
        }
        
        if(i-j > 1){
            ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i-1]));
        }
                
        else{
            ans.push_back(to_string(nums[i-1]));
        }
        
        return ans;
        
    }
};