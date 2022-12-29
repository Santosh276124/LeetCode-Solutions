//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        // code here
        stack<int> s;
        
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] > 0)
            {
                s.push(a[i]);
            }
            
            else //a[i] < 0
            {
                bool flag = true;
                while(!s.empty())
                {
                    //1
                    if(s.top() < 0) break;
                    
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends