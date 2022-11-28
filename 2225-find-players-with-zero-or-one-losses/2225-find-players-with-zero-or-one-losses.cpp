class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> lost;
        unordered_map<int,int> win;
        for(auto l : matches)
        {
            lost[l[1]]++;
            win[l[0]]++;
        }
        
        vector<vector<int>> ans;
        set<int> first;
        set<int> second;
        for(auto val : matches)
        {
            if(lost.count(val[0]) == false && win.count(val[0]) == true)
            {
                first.insert(val[0]);
            }
            
            if(lost[val[1]] == 1)
            {
                second.insert(val[1]);
            }
        }
        vector<int> v1;
        vector<int> v2;
        
        for(auto s : first)
        {
            v1.push_back(s);
        }
        for(auto s : second)
        {
            v2.push_back(s);
        }
        
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};