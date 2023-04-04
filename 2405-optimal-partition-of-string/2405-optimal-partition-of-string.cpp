class Solution {
public:
    /*
    vector<vector<string>> ans;
    
    bool isOptimal(string &s){
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        
        return s.length() == mp.size();
    }
   void  solve(int ind, string &s, vector<string> temp){
        if(ind >= s.length()){
            ans.push_back(temp) ;
            return;
        }
        
        int n = s.length();
        
        for(int i = ind; i < n; i++){
            string part = s.substr(ind, i-ind+1);
            if(isOptimal(part)){
                temp.push_back(part);
                solve(i+1, s, temp);
                temp.pop_back();
            }
        }
    }
    
    */
    int partitionString(string s) {
        
//         vector<string> temp;
//         solve(0, s, temp);
        
//         int res = INT_MAX;
//         for(auto arr : ans){
            
//             int len = arr.size();
//             res = min(res, len);
//         }
        
        unordered_map<char,int> mp;
        int n = s.length();
        
        int j = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            
            mp[s[i]]++;
            
            if(mp.size() == i-j+1){
              continue;
            }
            
            else if(mp.size() < i-j+1){
                cnt++;
                while(j < i){
                    mp[s[j]]--;
                    if(mp[s[j]] == 0){
                        mp.erase(s[j]);
                    }
                    
                    j++;
                }
               
            }
           
            
        }
        
        return cnt;
        
    }
};