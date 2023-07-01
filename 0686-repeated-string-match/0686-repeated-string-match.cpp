class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int m = b.length();
        
        string temp = a;
        
        int cnt = 1;
        
        while(temp.size() < b.size()){
            temp += a;
            cnt++;
        }
        
        for(int i = 0; i < temp.length(); i++){
            if(temp.substr(i, m) == b)
                return cnt;
        }
        
        temp += a;
        cnt++;
        
        for(int i = 0; i < temp.length(); i++){
            if(temp.substr(i, m) == b)
                return cnt;
        }
        
        return -1;
    }
};