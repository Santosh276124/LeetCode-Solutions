class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a = "";
        string b = "";
        
        for(int i = 0; i < word1.size(); i++)
        {
            a += word1[i];
          
        }
        
        for(int j = 0; j < word2.size(); j++)
              b += word2[j];
      
    
        if(a == b) return true;
        return false;
    }
};