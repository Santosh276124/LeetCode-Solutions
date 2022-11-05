class Solution {
    bool isFeasible(int k, vector<int> &nums, int d)
    {
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum > k)
            {
                sum = nums[i];
                cnt++;
                if(cnt > d)
                    return false;
            } 
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
     
        int sum = 0;
        for(auto i : weights)
            sum += i;
        
        int s = *max_element(weights.begin(), weights.end());
        int e = sum;
        
        while(s < e)
        {
            int mid = s+(e-s)/2;
            
            if(isFeasible(mid, weights, days))
                e = mid;
            else
                s = mid+1;
        }
        return s;
        
    }
};