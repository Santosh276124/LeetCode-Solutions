//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        int n = s.size();
      
        unordered_map<string, vector<int> > m;
        for(int i = 0; i < n; i++)
        {
            string temp = s[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : m)
        {
            vector<string> res;
            for(auto j : i.second)
            {
                res.push_back(s[j]);
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends