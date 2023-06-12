class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        
        sort(nums.begin(), nums.end());
      
      int len = 1;
      
      int j = 0;
      
      int curr = 1;
      
      for(int i = 0; i < n-1; i++){
          
          if(nums[i+1] == nums[i])
            continue;
          
          if(nums[i+1]-nums[i] == 1){
              curr++;
              len = max(len, curr);
              
          }
          else{
              curr = 1;
          }
          
      }
      
      return len;
        
    }
};