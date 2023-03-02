class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0;
        int ans = 0;
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            chars[ans++]=chars[i];
            int count = j-i;
            if(count>1){
            string s = to_string(count);
            for(int i=0;i<s.length();i++){
                chars[ans++]=s[i];
            }
            }
            i=j;
        }
        return ans;
    }
};