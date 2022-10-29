class Solution {
   static bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        return p1.second > p2.second;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
       int n = plantTime.size();
        
        vector<pair<int,int>> vec;
        
        for(int i = 0; i < n; i++)
            vec.push_back({plantTime[i], growTime[i]});
        
        sort(vec.begin(), vec.end(), comp);
        
        int ans = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++)
        {
            start += vec[i].first;
            
            ans = max(ans, start + vec[i].second);
        }
        
        return ans;
    }
};