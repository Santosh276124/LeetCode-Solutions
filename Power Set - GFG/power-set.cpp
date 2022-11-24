//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void solve(int ind, string &s, string output, vector<string> &ans)
    {
        // base case
        if(ind >= s.length())
        {
            if(output.length())
              ans.push_back(output);
              
            return;
        }
        //exclude
        solve(ind+1, s, output, ans);
        
        //include
        output += s[ind];
        solve(ind+1, s, output, ans);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string> ans;
		    string output = "";
		    
		    solve(0, s, output, ans);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends