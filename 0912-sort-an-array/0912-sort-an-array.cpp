           
              // Merge Sort:::::::::://Merge sort::::::

class Solution {
    
    void conquer(vector<int>& nums, int s, int mid, int e)
    {
        
        
        int length = e-s+1;
        vector<int> merged(length);
        
        
        int idx1 = s;
        int idx2 = mid+1;
        int k = 0;
        
        while(idx1 <= mid && idx2 <= e)
        {
            if(nums[idx1] <= nums[idx2])
            {
                merged[k++] = nums[idx1++];
                
            }
            else
            {
                merged[k++] = nums[idx2++];
            }
        }
        
        while(idx1 <= mid)
        {
            merged[k++] = nums[idx1++];
        }
        
        while(idx2 <= e)
        {
            merged[k++] = nums[idx2++];
        }
        
        for(int i = 0, j = s; i < length; i++,j++)
        {
            nums[j] = merged[i];
        }
        
       
    }
    
    
  void divide(vector<int>& nums, int s, int e)
    {
      if(s >= e) return;
      
        int mid = s + (e-s)/2;
        
        divide(nums,s, mid);
        divide(nums, mid+1, e);
      
        
       conquer(nums,s , mid, e);
      
    }
    
    
public:
    vector<int> sortArray(vector<int>& nums) {
        
        // if(nums.size() <= 1) return nums;
        
        int n = nums.size();
       divide(nums, 0, n-1);
        
        return nums;
        
         
    }
};