class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
//         Moores voting alogo
        
        int cnt = 0;
        int el;
        
        for(int i=0; i <nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el != nums[i])
                cnt--;
            else
                cnt++;
        }
        
        return el;
        
    }
};