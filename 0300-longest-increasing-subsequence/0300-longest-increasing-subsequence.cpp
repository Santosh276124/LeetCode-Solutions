class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        
        int n = a.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
       
          
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int prevInd = ind-1; prevInd >= -1; prevInd--)
            {
                  int excl = 0 + next[prevInd+1];
                  int incl = 0;
                  if(prevInd == -1 || a[ind] > a[prevInd] )
                        incl = 1 + next[ind+1];
                        
                   curr[prevInd+1] = max(excl, incl);
            }
            next = curr;
        }
        return curr[-1+1];
    }
};