class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {

            vector<int> f1(26, 0);
            vector<int> curr(26, 0);
            
            for(int i = 0; i < s1.length(); i++)
                f1[s1[i]-'a']++;
            
            int n = s1.length();
            
            int j = 0;
            int i = 0;
            while(i < s2.length())
            {
                curr[s2[i]-'a']++;
                
                if(i-j+1 == s1.length()){
                    if(curr == f1)
                        return true;
                }
                
                if(i-j+1 < s1.length())
                {
                    i++;
                }
                else //(i-j+1 >= s1.length())
                {
                    curr[s2[j]-'a']--;
                    i++;
                    j++;
                }
                
            }
           
   
            return false;
           	
        }
};