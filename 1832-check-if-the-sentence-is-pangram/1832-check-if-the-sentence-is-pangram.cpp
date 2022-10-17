class Solution {
public:
    bool checkIfPangram(string s) {
        
        unordered_map<char, bool> m;
        
        for(char i = 'a'; i <= 'z'; i++)
            m[i] = false;
        
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]] = true;
        }
        
        for(auto i : m)
        {
            if(i.second == false) return false;
        }
        return true;
    }
};