class Solution {
public:
    vector<string> ans;
    void solve(int ind, string &s, string path, long resSoFar, long prevNum, int tar){
        
        if(ind >= s.length()){
            if(resSoFar == tar)
                ans.push_back(path);
            
            return;
        }
        
        string curr = "";
        long currNum = 0;
        
        for(int j = ind; j < s.length(); ++j){
            
            if(j > ind && s[ind] == '0') break;  //leading 0 are not allowed
            
            curr += s[j];
            currNum = currNum * 10 + (s[j]-'0');
            
            if(ind == 0){
                solve(j+1, s, path + curr, currNum, currNum, tar);
            }
            
            else{
                
                solve(j+1, s, path + '+' + curr, resSoFar + currNum, currNum, tar);
                
                solve(j+1, s, path + '-' + curr, resSoFar - currNum, -currNum, tar);
                
                solve(j+1, s, path + '*' + curr, 
                      resSoFar -prevNum + (prevNum * currNum), prevNum * currNum, tar);
                
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        
        int n = num.length();
        
        
        
        solve(0, num, "", 0, 0, target);
        
        
        return ans;
        
    }
};