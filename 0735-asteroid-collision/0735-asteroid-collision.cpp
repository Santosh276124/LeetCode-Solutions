class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)
            {
                s.push(a[i]);
            }
            else  //a[i] < 0
            {
                 bool flag = true;
                while(!s.empty())
                {
                    //1
                    if(s.top() < 0) 
                        break;
                    
                    else if(s.top() > 0 && s.top() < abs(a[i]))
                        s.pop();
                    
                    else if(s.top() > 0 && s.top() > abs(a[i]))
                    {
                        flag = false;
                        break;
                    }
                    
                    else if(s.top() == abs(a[i]))
                    {
                        flag = false;
                        s.pop();
                        break;
                    }
                }
                
                if(flag)
                {
                    s.push(a[i]);
                }
            }
        }
        
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};