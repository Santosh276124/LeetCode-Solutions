class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.length();
        
        if(k == 1)
        {
            string doubleStr = s+s;
            string ans = s;
            for(int i = 1; i < n; i++)
            {
                string str = doubleStr.substr(i, n);
                
                if(str < ans)
                    ans = str;
                    
            }
            
            return ans;
        }
        
        //for k > 1
        sort(s.begin(), s.end());
        return s;
        
    }
};