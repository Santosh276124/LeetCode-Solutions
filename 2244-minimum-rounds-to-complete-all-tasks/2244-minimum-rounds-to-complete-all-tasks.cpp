class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> m;
        
        for(int i = 0; i < tasks.size(); i++)
        {
            m[tasks[i]]++;
        }
        
        int cnt = 0;
        for(auto el : m)
        {
            if(el.second <= 1) return -1;
            
            else if(el.second%3 == 0)
            {
                cnt += el.second/3;
            }
            else
            {
                cnt += el.second/3 + 1;
            }
            
        }
        
        return cnt;
    }
};