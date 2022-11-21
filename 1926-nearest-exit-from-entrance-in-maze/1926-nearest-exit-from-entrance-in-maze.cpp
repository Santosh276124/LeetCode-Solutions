class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int,int>> q; //x y index
        
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
        int steps = 1;
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                
                for(int j = 0; j < 4; j++)
                {
                    int newx = x + dir[j][0];
                    int newy = y + dir[j][1];
                    
                    //invalid
                    if(newx < 0 || newx >= n || newy < 0 || newy >= m || maze[newx][newy] == '+')
                        continue;
                    
                    //reaches boundary
                    if(newx == 0 || newx == n-1 || newy == 0 || newy == m-1)
                        return steps;
                    
                    maze[newx][newy] = '+';
                    q.push({newx, newy});
                }
            }
            steps++;
        }
        return -1;
    }
};