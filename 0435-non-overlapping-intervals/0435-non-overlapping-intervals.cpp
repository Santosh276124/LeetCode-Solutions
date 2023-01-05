class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
       sort(in.begin(), in.end());
        
        int cnt = 0;
        int end = in[0][1];
        for(int i = 1; i < in.size(); i++)
        {
            if(in[i][0] < end)
            {
                cnt++;
                end = min(end, in[i][1]);
            }
            
           else 
             end = in[i][1];
            
        }
        return cnt;
    }
};