class Solution
{
    public:
        string minWindow(string s, string t)
        {

            unordered_map<char, int> map;

            int i = 0, minlen = INT_MAX, count;
            string ans;

            for (char c: t)
            {
                map[c]++;
            }

            count = map.size();

            for (int j = 0; j < s.length(); j++)
            {
                if (map.find(s[j]) != map.end())
                {
                    map[s[j]]--;
                    if (map[s[j]] == 0)
                        count--;
                }
                while (count == 0)
                {
                    if (j - i + 1 < minlen)
                    {
                        minlen = j - i + 1;
                        ans = s.substr(i, minlen);
                    }
                    if (map.find(s[i]) != map.end())
                    {
                        map[s[i]]++;
                        if (map[s[i]] > 0) count++;
                    }
                    i++;
                }
            }

            return ans;
        }
};