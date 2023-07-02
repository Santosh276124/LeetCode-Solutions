class Solution {
public:
    int strStr(string h, string s) {
        
        int n = h.length();
        int m = s.length();
        
        for(int i = 0; i < n; i++){
            
            if(s == h.substr(i, m))
                return i;
            
        }
        
        return -1;
        
    }
};