class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> pref(n);
        vector<long long> suff(n);
        long long sum1  =0;
        long long sum2 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += nums[i];
            pref[i] = sum1;
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            sum2 += nums[i];
            suff[i] = sum2;
        }
        
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<suff[i]<<" ";
        // }
        
        long long diff = INT_MAX;
        int minInd = 0;
        for(int i = 0; i < n; i++)
        {
            long long difftilli1 = pref[i]/(i+1);
            
            long long difftilli2 = 0;
            if(i != n-1)
               difftilli2 = suff[i+1]/(n-i-1);
            
            long long currdiff = abs(difftilli1-difftilli2);
            // cout<<currdiff<<" ";
            if(currdiff < diff)
            {
                minInd = i;
                diff = currdiff;
            }
        }
        return  minInd;
    }
};