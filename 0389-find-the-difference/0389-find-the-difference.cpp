class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int c = 0;
        
        s += t;
        
        for(auto i : s)
            c^=i;
        
        return c;
    }
};