class Solution {
    
public:
   static bool cmp(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        
       string ans = "";
      
        unordered_map<char,int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        
      vector<pair<char,int>> v;
        for(auto i : m)
            v.push_back(i);
        
        sort(v.begin(), v.end(), cmp);
        
        for(auto j : v)
        {
            char ch = j.first;
            if(j.second > 1)
            {
                for(int i = 0; i < j.second; i++)
                    ans += ch;
            }
            else
                 ans += ch;
           
           
        }
        
        
        return ans;
        
        
        
    }
};