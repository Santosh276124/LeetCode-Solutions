class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {

            if (trust.size() == 0 && n == 1) return n;

            
            vector<int> in(n+1, 0);
            vector<int> out(n+1, 0);
            
            for(auto child : trust)
            {
                out[child[0]]++;
                in[child[1]]++;
            }
            
            for(int i = 1; i <= n; i++)
            {
                if(out[i] == 0 && in[i] == n-1) 
                    return i;
            }
            
            return -1;
        }
};