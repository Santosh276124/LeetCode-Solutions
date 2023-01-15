class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        int n = a.size();
        
        int i = 0;
        int j = 1;
        
        while(j < n)
        {
            if(i >= 0 && a[i] > 0 && a[j] < 0)
            {
                if(a[i] == abs(a[j]))
                {
                    i--;
                    j++;
                }
                else if(a[i] > abs(a[j]))
                    j++;
                else 
                    i--;
            }
            else
            {
                a[i+1] = a[j];
                i++;
                j++;
            }
        }
        
        vector<int> ans;
        
        for(int j = 0; j <= i; j++)
        {
            ans.push_back(a[j]);
        }
        
        return ans;
    }
};