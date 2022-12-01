class Solution {
public:
    bool halvesAreAlike(string s) {
        
       
       int count = 0;
        
        
    for(int i = 0; i < s.length(); i++)
      {
            s[i] = tolower(s[i]);
            
         if( i < s.length()/2)  
         {  
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
         }   
        
        else
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count--;
            }
        }
        
        
       }
        
        return (count==0);
        
        
    }
};