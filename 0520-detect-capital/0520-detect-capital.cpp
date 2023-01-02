class Solution {
    bool isCapital(char ch)
    {
        set<char> s;
        
        for(char c = 'A'; c <= 'Z'; c++)
        {
            s.insert(c);
        }
        
        if(s.find(ch) != s.end()) return true;
        return false;
    }
        
public:
    bool detectCapitalUse(string word) {
        
        int len = word.length();
        int cap = 0;
        for(int i = 0; i < len; i++)
        {
            if(isCapital(word[i]))
                cap++;
        }
        
        if(cap==0 || ( cap == 1 && isCapital(word[0]) ) || cap == len) return true;
        return false;
    }
};