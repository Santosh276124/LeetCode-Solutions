class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        // cout<<__gcd(n,m)<<" ";
        string ans = str1.substr(0, __gcd(n,m));
        
        return str1+str2 == str2+str1 ? ans : "";
    }
};