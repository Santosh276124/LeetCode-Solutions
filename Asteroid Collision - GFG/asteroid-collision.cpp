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
                // case1 s.top > 0 && < a[i]
                while(!s.empty() && s.top() > 0 && s.top() < abs(a[i]))
                  s.pop();
                  
                // case2  s.top() > 0 && > a[i]
                // kuchh nhi krna hai (i++) handled by for loop
                
                // case 3
                if(s.empty() || s.top() < 0)
                  s.push(a[i]);
                  
                // case 4 -> s.top == abs(a[i])
                if(!s.empty() && s.top() + a[i] == 0)
                  s.pop(); // i++ handled by for loop
                
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