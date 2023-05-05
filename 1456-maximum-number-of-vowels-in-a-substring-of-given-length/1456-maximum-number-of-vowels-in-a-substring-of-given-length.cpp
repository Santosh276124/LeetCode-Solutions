class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch=='u';
    }
    
    int maxVowels(string s, int k) {
        
        int ans = INT_MIN;
        
        int cnt = 0;
        
        int j = 0;
        
        for(int i = 0; i  < s.length(); i++){
            
            if(isVowel(s[i]))
                cnt++;
            
            if(i-j+1 == k){
                ans = max(ans, cnt);
                
                if(isVowel(s[j])){
                    cnt--;
                    j++;
                }
                else
                    j++;
                
            }
            
        }
        
        return ans;
    }
};