class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_map<string, int> mp;
        unordered_map<string,bool> vis;
        
        vector<char> choice{'A','C', 'G', 'T'};
        
        for(auto i : bank)
            mp[i]++;
        
        queue<string> q;
        q.push(start);
        
        vis[start] = true;
        
        int cnt = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                q.pop();
                
                if(curr == end) return cnt;
                
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i];
                    
                    for(int j = 0; j < 4; j++)
                    {
                        curr[i] = choice[j];
                        
                        if(mp.count(curr) && !vis[curr])
                        {
                            q.push(curr);
                            vis[curr] = true;
                        }
                    }
                    
                    curr[i] = orig;
                }
            }
            
            cnt++;
        }
        
        return -1;
        
    }
};