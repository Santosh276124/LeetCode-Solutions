//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            
           
              
            if(!st.empty() && s[i] == st.top())
             {
                 st.pop();
                 continue;
             }
             
            
            st.push(s[i]);
        }
        
        string ans = "";
        
        if(st.size() == 0) return "-1";
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return  ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends