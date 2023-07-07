class Solution {
public:

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.length();
        
        int j = 0;
        int cnt_T = 0, cnt_F = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
        
            if(answerKey[i] == 'T')
                cnt_T++;
            else
                cnt_F++;
            
            while(min(cnt_T, cnt_F) > k){
                if(answerKey[j] == 'T')
                    cnt_T--;
                else
                    cnt_F--;
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
 

        
       
        
    }
};