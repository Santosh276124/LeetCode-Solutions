class Solution {
public:
    int totalTimeTofinishWithMidSpeed(int mid, vector<int> &piles)
    {
        int cnt = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            if(piles[i] < mid)
                cnt++;
            else if(piles[i]%mid == 0)
                cnt += piles[i]/mid;
            else
                cnt += (piles[i]/mid + 1);
        }
        
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        
        while(s < e)
        {
            int mid = s + (e-s)/2;
            
            if(totalTimeTofinishWithMidSpeed(mid, piles) <= h)
                e = mid;
            else
                s = mid+1;
        }
        
        return s;
        
        
    }
};