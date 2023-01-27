class Solution {
public:
    bool isConcatenated(string &s, map<string,int>& mp)
    {
        for(int i = 0; i < s.length(); i++)
        {
            string pref = s.substr(0, i+1);
            string suff = s.substr(i+1);
            
            if(mp.count(pref) && mp.count(suff))
                return true;
            
            else if(mp.count(pref) && isConcatenated(suff, mp))
                return true;
        }
        
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        
        map<string,int> mp;
        for(int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        
         vector<string> ans;
        
        for(auto s : words)
        {
            bool check =  isConcatenated(s, mp);
            
            if(check) ans.push_back(s);
        }
        
        return ans;
    }
};