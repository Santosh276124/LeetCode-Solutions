class Solution {
public:
    string convertToTitle(int columnNumber) {
        
       string ans = "";
        
        while(columnNumber)
        {
            columnNumber-=1;
            char temp = 'A' + (columnNumber)%26;
            ans  = temp + ans;
            
            columnNumber = columnNumber/26;
            
        }
        
        return ans;
    }
};