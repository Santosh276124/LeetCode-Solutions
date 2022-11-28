class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> lost;
       
        for(auto l : matches)
        {
            lost[l[1]]++;
        }
        
        vector<vector<int>> ans;
        vector<int> win;
        vector<int> looser;
        
        for(auto val : matches)
        {
            if(lost[val[1]] == 1)
            {
                looser.push_back(val[1]);
            }
            
            if(lost.count(val[0]) == false)
            {
                win.push_back(val[0]);
                lost[val[0]] = 2;
            }
        }
       
        sort(win.begin(), win.end());
        sort(looser.begin(), looser.end());
      
        ans.push_back(win);
        ans.push_back(looser);
        return ans;
    }
};