
class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        vector<string> ans;
        
        map<string,int> m;
        for(int i =0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        
        for(auto &i : m)
        {
            pq.push({i.second,i.first});
        }
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
      
        return ans;
    }
};