class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
       // 1 2 2 5 7 10
           
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(i-2 >= 0)
            {
                 int a = nums[i];
                int b = nums[i-1];
                int c = nums[i-2];

                if(a+b > c && b+c > a && c + a > b)
                {
                    return a+b+c;
                }
               
            }
           
            
        }
        return 0;
        
        
    }
};