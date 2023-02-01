class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        
        return gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        // cout<<__gcd(n,m)<<" ";
        string ans = str1.substr(0, gcd(n,m));
        
        return str1+str2 == str2+str1 ? ans : "";
    }
};