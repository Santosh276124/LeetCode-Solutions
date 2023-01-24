class Solution {
public:
    pair<int,int> findNewCoordinates(int x, int n)
    {
        int r =n - (x-1)/n - 1;
        int c = (x-1)%n;
        
        if(r%2 == n%2)
            return {r, n-c-1};
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        
        int steps = 0;
        
        queue<int> q;
        q.push(1);
        
        vector<vector<bool>> vis(n,vector<bool>(n, false));
        
        vis[n-1][0] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                int x = q.front();
                q.pop();
                
                if(x == n*n) return steps;
                
                for(int j = 1; j <= 6; j++)
                {
                    int newx = x+j;
                    if(newx > n*n) break;
                    
                    pair<int,int> p = findNewCoordinates(newx, n);
                    
                    if(vis[p.first][p.second]) continue;
                    
                    vis[p.first][p.second] = true;
                    
                    if(board[p.first][p.second] != -1)
                        q.push(board[p.first][p.second]);
                    else
                        q.push(newx);
                }
            }
            steps++;
        }
        return -1;
    }
};