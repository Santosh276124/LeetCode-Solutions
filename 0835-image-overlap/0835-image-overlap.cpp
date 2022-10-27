class Solution {
    
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
      //main trick in this question is each 1 will be moving equal distance
        //if we try to find the difference between the resultant img coordinate and the input image which will result into the common points 
        
        //and max of the common point will be the answer.
        vector<pair<int,int>>vec1;
        vector<pair<int,int>>vec2;
        int n=img1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                {
                    vec1.push_back({i,j});
                }
                
                if(img2[i][j]==1)
                {
                    vec2.push_back({i,j});
                }
            }
        }
        
        map<pair<int,int>,int>m;
        int ans=0;
        for(auto it:vec1)
        {
            for(auto itx:vec2)
            {
                int x=itx.first-it.first;
                int y=itx.second-it.second;
                
                m[{x,y}]++;
                ans=max(ans,m[{x,y}]);
            }
        }
        
        return ans;
    }
};