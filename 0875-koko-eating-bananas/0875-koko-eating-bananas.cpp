class Solution {
    bool isFeasible(int k, vector<int> &piles, int h)
    {
        int cnt = 0;
        
        for(auto pile : piles)
        {
            if(pile <= k)
                cnt++;
            else
            {
                if(pile%k != 0)
                    cnt += (pile/k + 1);
                else
                    cnt += pile/k;
                    
            }
            
            if(cnt > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        
        while(s < e)
        {
            int mid = s+(e-s)/2;
            
            if(isFeasible(mid, piles, h))
                e = mid;
            else
                s = mid+1;
        }
        return s;
    }
};