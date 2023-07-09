class Solution {
public:
    int largestVariance(string s) {
        
       
        int ans = 0;
        
        for(int max_char = 'a'; max_char <= 'z'; max_char++){
            
            for(int min_char = 'a'; min_char <= 'z'; min_char++)
            {
                if(max_char == min_char)
                    continue;
                
                int max_char_cnt = 0;
                int min_char_cnt = 0;
                bool can_extent_interval = false;
                
                for(int i = 0; i < s.length(); i++){
                    
                    char ch = s[i];
                    
                    if(ch == max_char) max_char_cnt++;
                    if(ch == min_char) min_char_cnt++;
                    
                    if(min_char_cnt > 0)
                        ans = max(ans, max_char_cnt - min_char_cnt);
                    
                    else{
                        
                        if(can_extent_interval)
                            ans = max(ans, max_char_cnt - 1);
                        
                    }
                    
                    if(min_char_cnt > max_char_cnt){
                        max_char_cnt = 0;
                        min_char_cnt = 0;
                        can_extent_interval = true;
                    }
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};