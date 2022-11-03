class Solution {

public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> m;
        
        for(auto i : words)
            m[i]++;
        
        int cnt = 0;
        bool flag = false;
        for( auto s : words)
        {
            string temp = s;
            reverse(temp.begin(), temp.end());
            
            
            if(temp != s && m[temp] > 0 && m[s] > 0)
            {
                 cnt += 4;
                m[temp]--;
                m[s]--;
               
            }
            else if(temp == s && m[s] > 0 && m[s]%2 == 1)
            {
                if(flag == false)
                {
                    cnt += 2*m[s];
                    m[s] = 0;
                    flag = true;
                }
                else
                {
                    cnt += (2*(m[s]-1));
                    m[s] = 0;
                }
            }
            else if(temp == s && m[s]%2 == 0 && m[s] > 0)
            {
                 cnt += (2*m[s]);
                 m[s] = 0;
               
            }
          
        }
        return cnt;
    }
};