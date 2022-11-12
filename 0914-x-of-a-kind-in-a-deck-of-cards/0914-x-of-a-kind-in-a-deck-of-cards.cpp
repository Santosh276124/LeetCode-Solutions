class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
//         sort(deck.begin(), deck.end());
        
//         for(int i = 0; i < deck.size(); i++)
//         {
            
//         }
        
           unordered_map<int,int> m;
        
        if(deck.size() == 1) return false;
        
        for(int i = 0; i < deck.size(); i++)
            m[deck[i]]++;
        
        int res = 0;
        for(auto i : m)
        {
            res = __gcd(i.second, res);
        }
      
        return res>1;
        
    }
};