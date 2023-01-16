class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // if(intervals.size() < 1) return newInterval;
        
        intervals.push_back(newInterval);
        
        int n = intervals.size();
        
        
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
        
        
    }
};