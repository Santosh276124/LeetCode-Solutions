class Solution {
public:
    int solve(string answerKey, int k, char ch){
        
        int n = answerKey.length();
        
        int j = 0;
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
        
            if(answerKey[i] == ch)
                cnt++;
            
            while(cnt > k){
                if(answerKey[j] == ch)
                    cnt--;
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
        
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
 
        return max(solve(answerKey, k, 'F'), solve(answerKey, k, 'T'));
        
       
        
    }
};