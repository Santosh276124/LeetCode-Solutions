//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& w) {
        // Code here
        unordered_map<string,int> mp;
        for(auto word : w)
        {
            mp[word]++;
        }
        
        queue<pair<string,int>> q;
        q.push({s, 1});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            string st = front.first;
            int d = front.second;
            
            if(st == t) return d;
            
            for(int i = 0; i < st.length(); i++)
            {
                string temp = st;
                for(int j = 0; j < 26; j++)
                {
                    if(st[i] == 'a' + j) continue;
                    
                    st[i] = 'a' + j;
                    
                    if(mp.count(st))
                    {
                        q.push({st, d+1});
                        mp.erase(st);
                    }
                }
                
                st = temp;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends