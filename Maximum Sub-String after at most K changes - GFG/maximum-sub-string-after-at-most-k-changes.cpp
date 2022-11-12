//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    
		    unordered_map<char,int> m;
		    
		    int maxLen = 0;
		    int windowSize = 0;
		    int maxOcc = 0;
		    int j = 0;
		    
		    for(int i = 0; i < s.length(); i++)
		    {
		        m[s[i]]++;
		        maxOcc = max(maxOcc, m[s[i]]);
		        windowSize = i-j+1;
		        
		        if(windowSize - maxOcc <= k)
		          maxLen = max(maxLen , windowSize);
		        else
		        {
		            m[s[j]]--;
		            j++;
		        }
		    }
		    
		    return maxLen;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends