class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
       map<string, int> m;
        
        string temp = "";
        
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] == ' ')
            {
                m[temp]++;
                temp = "";
            }
             else  
              temp += s1[i];
            
        }
        m[temp]++;
        
        string temp1 = "";
        
        for(int i = 0; i < s2.size(); i++)
        {
            if(s2[i] == ' ')
            {
                m[temp1]++;
                temp1 = "";
            }
              
            else
             temp1 += s2[i];
            
        }
        m[temp1]++;
        
        vector<string> ans;
        
        for(auto i : m)
        {
            if(i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};