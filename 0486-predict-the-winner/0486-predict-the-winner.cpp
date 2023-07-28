class Solution {
public:
    int find(int i, int j, int f, int firstsc, int secondsc,  vector<int> &nums){
        
        if(i > j) return firstsc >= secondsc;
        

        
        if(f){
            
            return  find(i+1, j, 0, firstsc + nums[i], secondsc, nums) ||
                       find(i, j-1, 0, firstsc + nums[j], secondsc, nums) ;
            
        }
        else{
            
            return  find(i+1, j, 1, firstsc , secondsc + nums[i] ,nums) &&
                        find(i, j-1, 1, firstsc, secondsc + nums[j], nums);
        }
         
        // return firstsc >= secondsc;
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        
        // int total = accumulate(nums.begin(), nums.end(), 0);
        
       return find(0, n-1, 1, 0, 0, nums);
        
        
        
    }
};