class Solution {
public:
    bool isItPossible(string w1, string w2) {
       
        int n = w1.length();
        int m = w2.length();
       unordered_map<char,int> m1,m2;
        
       for(int i = 0; i < n; i++) m1[w1[i]]++;
        for(int i = 0; i < m; i++) m2[w2[i]]++;
        
        for(char ch1 = 'a'; ch1 <= 'z';  ch1++)
        {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++)
            {
                if(m1.count(ch1) && m2.count(ch2))
                {
                    //swapping
                    //for ch1
                    m1[ch1]--;
                    if(m1[ch1] == 0) m1.erase(ch1);
                    m2[ch1]++;
                    //for ch2
                    m2[ch2]--;
                    if(m2[ch2] == 0) m2.erase(ch2);
                    m1[ch2]++;
                    
                    if(m1.size() == m2.size())
                        return true;
                    else
                    {
                        //again reverse to original mp
                        //for ch1
                        m1[ch1]++;
                        m2[ch1]--; 
                        if(m2[ch1] == 0) m2.erase(ch1);
                        //for ch2
                        m2[ch2]++;
                        m1[ch2]--;
                        if(m1[ch2] == 0) m1.erase(ch2);
                    }
                }
            }
        }
        return false;        
    }
};