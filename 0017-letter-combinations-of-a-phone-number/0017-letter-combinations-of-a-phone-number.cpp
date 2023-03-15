class Solution {
    
    int n;
    
    void solve(int ind, string &digits, string &temp, vector<string> &ans, vector<string> &mp)
    {
        if(ind >= n){
            ans.push_back(temp);
            
            return;
        } 
 
        string keyVal = mp[digits[ind] - '0'];
        for(int i = 0; i < keyVal.length(); i++)
        {
            temp += keyVal[i];
            solve(ind+1, digits, temp, ans, mp);
            
            temp.pop_back();
        }
    }
    
    
    
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        n = digits.length();
        
        if(n == 0) return ans;
        
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string temp = "";
        
        solve(0, digits, temp, ans, mp);
        
        return ans;
         
        
    }
};