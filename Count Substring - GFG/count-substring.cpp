//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        unordered_map<char,int> m;
        int cnt = 0;
        int j = 0;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
            
            if(m.size() >= 3)
            {
                while(m.size() >= 3)
                {
                    m[s[j]]--;
                    
                    if(m[s[j]] == 0)
                        m.erase(s[j]);
                    
                    j++;
                }
            }
            
            cnt += j;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends