class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        
        unordered_map<char,int> m;
        
        int maxLen = 0;
        int maxOcc = 0;
        int j = 0;
        int windowSize = 0;
        
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
            
            maxOcc = max(maxOcc, m[s[i]]);
            windowSize = i-j+1;
            
            if(windowSize - maxOcc <= k)
            {
                maxLen = max(maxLen, windowSize);
            }
            else
            {
                //start shrinking
                m[s[j]]--;
                j++;
            }
        }
        
        return maxLen;
    }
};