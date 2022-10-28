class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        int n = s.size();
        vector<string> st = s;
        unordered_map<string,vector<int> > m;
        for(int i = 0; i < n; i++)
        {
            sort(s[i].begin(), s[i].end());
            
            m[s[i]].push_back(i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : m)
        {
            vector<string> temp;
            
            for(auto j : i.second)
            {
                temp.push_back(st[j]);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};