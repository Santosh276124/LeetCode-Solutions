class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.length();
        int m = goal.length();
        
        //case1 
        if(s == goal){
            
            vector<int> hash(26,0);
            for(int i = 0; i < n; i++){
                hash[s[i]-'a']++;
                if(hash[s[i]-'a'] > 1)
                    return true;
            }
            
            return false;
            
        }
        
        //case2  s != goal
        int l = 0;
        int r = n-1;
        while(l < n && s[l] == goal[l])
            l++;
        while(r >= 0 && s[r] == goal[r])
            r--;
        
        if(l < r)
            swap(s[l], s[r]);
        
        
        
        
        
        return s == goal;
        
    }
};