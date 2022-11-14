class Solution {
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
public:
    int countVowelSubstrings(string word) {
        
        int n = word.length();
        int cnt = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(isVowel(word[i])){
      
                unordered_map<char,int> m;
                for(int j = i; j < n; j++)
                {
                    if(isVowel(word[j]))
                    {
                        m[word[j]]++;
                        if(m.size() == 5)
                            cnt++;
                    }
                    else
                        break;
                }
            }
        }
        return cnt;
    }
};