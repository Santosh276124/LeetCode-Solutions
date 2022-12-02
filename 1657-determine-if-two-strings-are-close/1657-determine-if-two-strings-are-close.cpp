class Solution {
public:
    bool closeStrings(string s1, string s2) {
        
        if(s1.length() != s2.length()) return false;
        
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        set<char>st1;
        set<char>st2;
        
        for(int i = 0; i < s1.length(); i++){
            m1[s1[i]]++;
            st1.insert(s1[i]);
        }
        
        for(int i = 0; i < s2.length(); i++)
        {
            m2[s2[i]]++;
            st2.insert(s2[i]);
        }
        
        // cout<<m1.size()<<" ";
        // cout<<m2.size()<<" ";
        vector<int> v1;
        vector<int> v2;
        
        for(auto i : m1)
        {
            // cout<<i.second<<" ";
            v1.push_back(i.second);
           
        }
        for(auto j : m2)
        {
            // cout<<j.second<<" "; 
            v2.push_back(j.second);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return (v1 == v2) && (st1==st2);
    }
};