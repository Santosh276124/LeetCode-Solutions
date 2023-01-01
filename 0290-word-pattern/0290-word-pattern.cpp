class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {

            unordered_map<string, vector <int> > ms;

            string temp = "";
            int ind = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == ' ')
                {
                    ms[temp].push_back(ind);
                    temp = "";
                    ind++;
                    continue;
                }

                temp += s[i];
            }

            ms[temp].push_back(ind);

            unordered_map<string, vector <int> > mp;
            temp = "";
            for (int i = 0; i < pattern.length(); i++)
            {
                temp += pattern[i];
                // cout<<temp<<" ";
                mp[temp].push_back(i);
                temp = "";
            }
            
            for(auto m : mp)
            {
                cout<< m.first <<" ";
            }
             for(auto m : ms)
            {
                cout<< m.first <<" ";
            }

            if (ms.size() != mp.size()) return false;
            
            vector<vector<int>> v1;
            vector<vector<int>> v2;
            
            for(auto m : mp)
            {
                sort(m.second.begin(), m.second.end());
                v1.push_back(m.second);
            }
            for(auto m : ms)
            {
                sort(m.second.begin(), m.second.end());
                v2.push_back(m.second);
            }
            
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            
            return v1==v2;

            // return true;
        }
};