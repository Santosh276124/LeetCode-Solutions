class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        
        for(int i = 0; i < t.length(); i++)
           m[t[i]]++;
        
        for(int i = 0; i < s.size(); i++)
        {
             if(m.count(s[i])) m[s[i]]--;
            
            
        }
        for(auto i : m)
        {
            if(i.second != 0) return i.first;
        }
           
        
        return '-1';
    }
};